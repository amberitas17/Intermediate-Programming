/* Manipulating Binary Files
Written by: Amber Clarisse Cubacub
Date Written: 06/09/22 */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

//structures to get data (item for item file, supply for supply file, sales for sales file, and purchase for purchase file
typedef struct item {
	int id;
    char iname[20];
	float price;
	int itemsoh;
} ITEM;

typedef struct supply {
	int snum;
    char sname[20];
	char sadd[30];
	char scontact[20];
} SUPPLY;

typedef struct sales {
	int transno;
	int date;
    int itemno;
	float price;
	int quant;
} SALES;

typedef struct purchase {
	int pno;
	int date;
	int snum;
	int itemno;
    float unitcost;
	int qtypurch;
	float subtotal;
} PURCHASE;
//menu
int CreateMenu1(void);
//submenus
int CreateMenuItm(void);
int CreateMenuSupps(void);
int CreateMenuSales(void);
int CreateMenuPurchase(void);
//adding new data
void ItemGro(int i, int *add, FILE *bp, ITEM itm);
void SupplyGro(int o, int *add2, FILE *bpsupps, SUPPLY supps);
void SalesGro(int p, int *add3, FILE *bptrans, FILE *bp, SALES sals, ITEM itm);
void PurchaseGro(int q, int *add4, FILE *bppurch, FILE *bp, FILE *bpsupps, PURCHASE purch, ITEM itm, SUPPLY supps);
//creating skeleton file
void CreateItem(FILE *bp, ITEM itm);
void CreateSupp(FILE *bpsupps, SUPPLY supps);
void CreateSales(FILE *bptrans, SALES sals);
void CreatePurch(FILE *bptrans, PURCHASE purch);
//item search, display, edit, delete
void SearchItem(FILE *bp, ITEM itm);
void DisplayItem(FILE *bp, ITEM itm);
void EditItem(FILE *bp, ITEM itm);
void DeleteItem(FILE *bp, ITEM itm);
//supply search, display, edit, delete
void SearchSupps(FILE *bpsupps, SUPPLY supps);
void DisplaySupps(FILE *bpsupps, SUPPLY supps);
void EditSupps(FILE *bpsupps, SUPPLY supps);
void DeleteSupps(FILE *bpsupps, SUPPLY supps);
//display sales and purchase
void DisplaySales(FILE *bptrans, SALES sals);
void DisplayPurchase(FILE *bppurch, PURCHASE purch);
//finding functions if the data already exists
int ItemNumber(int num);
int SuppsNumber(int num);
int SalesNumber(int num);
int PurchNumber(int num);
void gotoxy(short x, short y);

int main(void)
{
	//declaring files
	FILE *bp = 0;
	FILE *bptrans = 0;
	FILE *bpsupps = 0;
	FILE *bppurch = 0;
	//declaring structures
  	ITEM itm;
  	SUPPLY supps;
  	SALES sals;
  	PURCHASE purch;
  	
	char choice;
	int creatrec;
	int creatitem;
	int creatsupps;
	int creatsales;
	int creatpurch;
	int count = 0, i, count2 = 0, count3 = 0, count4 = 0, x, z, y;

	do{
		//menu 
		system("cls");
		printf("\nWelcome to Amber's Grocery Store\n");
		printf("\n [1] Create Records");
		printf("\n [2] Item");
		printf("\n [3] Suppliers");
		printf("\n [4] Sales");
		printf("\n [5] Purchase");
		printf("\n [6] Exit\n");
		scanf("%d", &choice);
		
		if(choice == 1){	
		//creating skeleton files
			do {
				creatrec = CreateMenu1();
				switch (creatrec) {
					case 1: CreateItem(bp, itm); break;
					case 2: CreateSupp(bpsupps, supps); break;
					case 3: CreateSales(bptrans, sals); break;
					case 4: CreatePurch(bppurch, purch); break;
				}
  			} while (creatrec != 4);
		}
		else if(choice == 2){
			//item submenus
			do {
				creatitem = CreateMenuItm();
				switch (creatitem) {
					case 1: ItemGro(i, &count, bp, itm); break;
					case 2: SearchItem(bp, itm); break;
					case 3: EditItem(bp, itm); break;
					case 4: DeleteItem(bp, itm); break;
					case 5: DisplayItem(bp, itm); break;
				}
  			} while (creatitem != 5);
		}
		else if(choice == 3){
			//supply submenus
			do {
				creatsupps = CreateMenuSupps();
				switch (creatsupps) {
					case 1: SupplyGro(y, &count2, bpsupps, supps); break;
					case 2: SearchSupps(bpsupps, supps); break;
					case 3: EditSupps(bpsupps, supps); break;
					case 4: DeleteSupps(bpsupps, supps); break;
					case 5: DisplaySupps(bpsupps, supps); break;
				}
  			} while (creatsupps != 5);
		}
		else if(choice == 4){
			//sales sub menu
			do {
				creatsales = CreateMenuSales();
				switch (creatsales) {
					case 1: SalesGro(x, &count3, bp, bptrans, sals, itm); break;
					case 2: DisplaySales(bptrans, sals); break;
				}
  			} while (creatsales != 2);
		}
		else if(choice == 5){
			//purchase sub menu
			do {
				creatpurch = CreateMenuPurchase();
				switch (creatpurch) {
					case 1: PurchaseGro(z, &count4, bp, bppurch,bpsupps, purch, itm, supps); break;
					case 2: DisplayPurchase(bppurch, purch); break;
				}
  			} while (creatpurch != 2);
		}
		else if(choice == 6){
			//exiting
			exit(0);
		}
	
	} while (choice < 6);
}

//finding if the data from the item file already exists
int ItemNumber(int num){
	FILE *bp;
	ITEM itm;
    bp = fopen("item.dat", "rb");
    while (fread(&itm, sizeof(ITEM), 1, bp))
    {
        if (itm.id == num)
        {
            fclose(bp);
            return -1;
        }
    }
    fclose(bp);

    return 1;
}

//finding if the data from the supply file already exists
int SuppsNumber(int num){
	FILE *bpsupps;
	SUPPLY supps;
    bpsupps = fopen("supply.dat", "rb");
    while (fread(&supps, sizeof(SUPPLY), 1, bpsupps))
    {
        if (supps.snum == num)
        {
            fclose(bpsupps);
            return -1;
        }
    }
    fclose(bpsupps);

    return 1;
}

//finding if the data from the sales file already exists
int SalesNumber(int num){
	FILE *bptrans;
	SALES sals;
    bptrans = fopen("sales.dat", "rb");
    while (fread(&sals, sizeof(SALES), 1, bptrans))
    {
        if (sals.transno== num)
        {
            fclose(bptrans);
            return -1;
        }
    }
    fclose(bptrans);

    return 1;
}


//finding if the data from the purchase file already exists
int PurchNumber(int num){
	FILE *bppurch;
	PURCHASE purch;
    bppurch = fopen("purch.dat", "rb");
    while (fread(&purch, sizeof(PURCHASE), 1, bppurch))
    {
        if (purch.pno == num)
        {
            fclose(bppurch);
            return -1;
        }
    }
    fclose(bppurch);

    return 1;
}

//menus
int CreateMenu1(void){
	int ch;
	system("cls");
	printf("\n [1] Item");
	printf("\n [2] Suppliers");
	printf("\n [3] Sales");
	printf("\n [4] Purchase\n");
	scanf("%d", &ch);
	return ch;
}

int CreateMenuItm(void){
	int choice2;
	system("cls");
	printf("\n [1] Add New Item");
	printf("\n [2] Search Item");
	printf("\n [3] Edit Item");
	printf("\n [4] Delete Item");
	printf("\n [5] Display Item\n");
	scanf("%d", &choice2);
	return choice2;
}

int CreateMenuSupps(void){
	int choice3;
	system("cls");
	printf("\n [1] Add New Supplier");
	printf("\n [2] Search Supplier");
	printf("\n [3] Edit Supplier");
	printf("\n [4] Delete Supplier");
	printf("\n [5] Display Supplier\n");
	scanf("%d", &choice3);
	return choice3;
}

int CreateMenuSales(void){
	int choice4;
	system("cls");
	printf("\n [1] Add New Sales Transaction");
	printf("\n [2] Display Sales Transaction\n");
	scanf("%d", &choice4);
	return choice4;
}

int CreateMenuPurchase(void){
	int choice5;
	system("cls");
	printf("\n [1] Add New Purchase Transaction");
	printf("\n [2] Display Purchase Transaction\n");
	scanf("%d", &choice5);
	return choice5;
}

//creating skeletons
void CreateItem(FILE *bp, ITEM itm){
	int i;

	bp = fopen("item.dat", "wb"); //creating a file
	if (bp == NULL)
	{
		printf("Error in opening file...");
		getch();
	}
	else
	{
		//creating empty data
		for (i=0; i<20; i++) {
			itm.id = 0;
			strcpy(itm.iname,"");
			itm.price = 0;
			itm.itemsoh = 0;
			fwrite(&itm, sizeof(ITEM), 1, bp);
		}
		system("cls");
		printf("Finished creating the Item Skeleton for the Relative File.");
		printf("\nThe skeleton can contain 20 records.");
		printf("\nPress any key to continue...");
		getch();
	}
	fclose(bp);
}

void CreateSupp(FILE *bpsupps, SUPPLY supps){
	int i;

	bpsupps = fopen("supply.dat", "wb");//creating a file
	if (bpsupps == NULL)
	{
		printf("Error in opening file...");
		getch();
	}
	else
	{
		for (i=0; i<20; i++) {
			//empty data
			supps.snum = 0;
			strcpy(supps.sname,"");
			strcpy(supps.sadd,"");
			strcpy(supps.sadd,"");
			strcpy(supps.scontact, "");
			fwrite(&supps, sizeof(SUPPLY), 1, bpsupps);
		}
		system("cls");
		printf("Finished creating the Supply Skeleton for the Relative File.");
		printf("\nThe skeleton can contain 20 records.");
		printf("\nPress any key to continue...");
		getch();
	}
	fclose(bpsupps);
}

void CreateSales(FILE *bptrans, SALES sals){
	int i;

	bptrans = fopen("sales.dat", "wb");//creating file
	if (bptrans == NULL){
		printf("Error in opening file...");
		getch();
	}
	else
	{
		for (i=0; i<20; i++) {
			//empty data
			sals.transno = 0;
			sals.date = 0;
			sals.itemno = 0;
			sals.quant = 0;
			sals.price = 0;
			fwrite(&sals, sizeof(SALES), 1, bptrans);
		}
		system("cls");
		printf("Finished creating the Sales Skeleton for the Relative File.");
		printf("\nThe skeleton can contain 20 records.");
		printf("\nPress any key to continue...");
		getch();
	}
	fclose(bptrans);
}

void CreatePurch(FILE *bppurch, PURCHASE purch){
	int i;

	bppurch = fopen("purch.dat", "wb");//creating file
	if (bppurch == NULL)
	{
		printf("Error in opening file...");
		getch();
	}
	else
	{
		for (i=0; i<20; i++) {
			//empty data
			purch.date = 0;
			purch.itemno = 0;
			purch.pno = 0;
			purch.qtypurch = 0;
			purch.snum = 0;
			purch.subtotal = 0;
			purch.unitcost = 0;
			fwrite(&purch, sizeof(PURCHASE), 1, bppurch);
		}
		system("cls");
		printf("Finished creating the Purchase Skeleton for the Relative File.");
		printf("\nThe skeleton can contain 20 records.");
		printf("\nPress any key to continue...");
		getch();
	}
	fclose(bppurch);
}

//adding item data
void ItemGro(int i, int *add, FILE *bp, ITEM itm){
	int itemid,itmsoh, found, s;
	float itemprice;
	char itemname[20];
	int count = i;//to add data
	system("cls");
	bp = fopen("item.dat", "r+b");//opening the data and writing the data
	printf("Enter Item Number: ");
	scanf("%d", &itemid);
	//if the item id that entered already exists
	if (ItemNumber(itemid) != 1){
        printf("\nInvalid item number. Number already taken!\n");
    }
	else{
		fflush(stdin);
		printf("Enter name: ");
		gets(itemname);
		printf("Enter price: ");
		scanf("%f", &itemprice);
		printf("Enter Item Stock on Hand: ");
		scanf("%d", &itmsoh);
		itm.id = itemid;
		strcpy(itm.iname, itemname);
		itm.price = itemprice;
		itm.itemsoh = itmsoh;
		//writing the data
		fseek(bp, itemid*sizeof(ITEM),SEEK_SET);
		fwrite(&itm,sizeof(ITEM),1,bp);
		fclose(bp);
		printf("Record added. Press any key to continue.");
		getch();
	
		count++;
		*add = count;
	}
}
void SearchItem(FILE *bp, ITEM itm){
    int number;

  	system("cls");
  	bp = fopen("item.dat", "rb"); //opening the data to read only
  	printf("Enter Item Number to display:");
  	scanf("%d",&number);
  	fseek(bp, number*sizeof(ITEM), SEEK_SET); //to read the data involved
  	fread(&itm, sizeof(ITEM), 1, bp);
  	if (itm.id == number){
  		printf("Item Number: %d\n", itm.id);
  		printf("Item Name: %s\n", itm.iname);
  		printf("Item Price: %.2f\n", itm.price);
  		printf("Item Stock on Hand: %d", itm.itemsoh);
	}

  	else
	  	printf("Item number not existed...");
  	getch();
  	fclose(bp);
}

void EditItem(FILE *bp, ITEM itm){
    float itmprice;
	int  number, choice, flag=0, itemstock;
	char itmname[20], answer;

	bp = fopen("item.dat", "r+b");//to open the file for edit and read
	system("cls");
	printf("Enter number:");
	scanf("%d", &number);
	fseek(bp, number*sizeof(ITEM), 0);
	fread(&itm, sizeof(ITEM), 1, bp);//reading the data
	
	if (number == itm.id) {
		printf("Item Number: %d\n", itm.id);
  		printf("Item Name: %s\n", itm.iname);
  		printf("Item Price: %.2f\n", itm.price);
  		printf("Item Stock on Hand: %d", itm.itemsoh);
  		printf("\nDo you want to edit?");
  		scanf("%c", &answer);
  		//if the user chooses to edit
		if (answer == 'Y' || answer == 'y'){
			printf("\n\nPress 1 to change the name\n");
			printf("Press 2 to change the price\n");
			printf("Press 3 to change the Stock on Hand");
			printf("Choice: ");
			scanf("%d", &choice);
			if (choice == 1) {
				fflush(stdin);
				printf("Enter new name: ");
				gets(itmname);
				strcpy(itm.iname, itmname);
			}
			if (choice == 2) {
				printf("Enter new price: ");
				scanf("%f", &itmprice);
				itm.price = itmprice;
			}
			if (choice == 3) {
				printf("Enter new stock on hand: ");
				scanf("%d", &itemstock);
				itm.itemsoh = itemstock;
			}
			//after finishing the edit
			fseek(bp, number*sizeof(ITEM), 0);
			fwrite(&itm, sizeof(ITEM), 1, bp);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("Record not here...");
	getch();
	fclose(bp);
}

void DeleteItem(FILE *bp, ITEM itm){
    int  number, response, flag=0;

	bp = fopen("item.dat", "r+b"); //reading the data
	system("cls");
	printf("Enter Item Number:");
	scanf("%d", &number);
	fseek(bp, number*sizeof(ITEM), 0);
	fread(&itm, sizeof(ITEM), 1, bp);
	if (number == itm.id) {
		printf("\nItem Number  : %d", itm.id);
		printf("\nItem Name    : %s", itm.iname);
		printf("\nPrice: %.2f", itm.price);
		printf("\nStock on Hand: %d", itm.itemsoh);
		printf("\n\nDELETE this record? (Y/N): ");
		scanf(" %c", &response);
		//if the user wants to delete data
		if (toupper(response) == 'Y') {
			//back to empty data
			itm.id = 0;
			strcpy(itm.iname, "");
			itm.price = 0;
			itm.itemsoh = 0;
			fseek(bp, number*sizeof(ITEM), 0);
			fwrite(&itm, sizeof(ITEM), 1, bp);
			flag = 1;
		}
		else {
			printf("DELETION ABORTED...Press any key to continue.");
			getch();
		}
	}
	if (flag == 0)
		printf("Record not here...");
	getch();
	fclose(bp);
     
}
//view all the data
void DisplayItem(FILE *bp, ITEM itm){
	int i, y=4;

	bp = fopen("item.dat", "rb");
	system("cls");
	printf("Item Number      Item Name           Item Price            Item Stock On Hand");

	for (i=0; i<20; i++) {
		fseek(bp, i*sizeof(ITEM), 0);
		fread(&itm, sizeof(ITEM), 1, bp);
			gotoxy(1, y); printf("%d", itm.id);
			gotoxy(20, y); printf("%s", itm.iname);
			gotoxy(50, y); printf("%.2f", itm.price);
			gotoxy(70, y); printf("%d", itm.itemsoh);
			y++;
	}
	getch();
}

void SupplyGro(int o, int *add2, FILE *bpsupps, SUPPLY supps){
	int supnum;
	char supname[20], supadd[20], supcontact[20];
	int count3 = o;
	
	system("cls");
	bpsupps = fopen("supply.dat", "r+b");//open the file
	printf("Enter Supplier Number: ");
	scanf("%d", &supnum);
	//if the data that the user entered is already existed
	if (SuppsNumber(supnum) != 1){
        printf("\nInvalid item number. Number already taken!\n");
    }
	else{
		fflush(stdin);
		printf("Enter Supplier name: ");
		gets(supname);
		fflush(stdin);
		printf("Enter Supplier Address: ");
		gets(supadd);
		fflush(stdin);
		printf("Enter Supplier Contact: ");
		gets(supcontact);
		supps.snum = supnum;
		strcpy(supps.sname, supname);
		strcpy(supps.sadd, supadd);
		strcpy(supps.scontact, supcontact);
		fseek(bpsupps, supnum*sizeof(SUPPLY),SEEK_SET);
		fwrite(&supps,sizeof(SUPPLY),1,bpsupps);
		fclose(bpsupps);
		printf("Record added. Press any key to continue.");
		getch();
		count3++;
		*add2 = count3;
	}
}
void SearchSupps(FILE *bpsupps, SUPPLY supps){
    int number;

  	system("cls");
  	bpsupps = fopen("supply.dat", "rb");
  	printf("Enter Supplier Number to display:");
  	scanf("%d",&number);
  	fseek(bpsupps, number*sizeof(SUPPLY), SEEK_SET);
  	fread(&supps, sizeof(SUPPLY), 1, bpsupps);
  	if (supps.snum == number){
  		printf("Supplier Number: %d\n", supps.snum);
  		printf("Supplier Name: %s\n", supps.sname);
  		printf("Supplier Address: %s\n", supps.sadd);
  		printf("Supplier Contact: %s", supps.scontact);
	}

  	else
	  	printf("Supplier number is not existing...");
  	getch();
  	fclose(bpsupps);
}

void EditSupps(FILE *bpsupps, SUPPLY supps){
	int  number, choice, flag=0;
	char suppname[20],suppadd[20],suppcontacts[20], answer;

	bpsupps = fopen("supply.dat", "r+b");
	system("cls");
	printf("Enter number:");
	scanf("%d", &number);
	fseek(bpsupps, number*sizeof(SUPPLY), 0);
	fread(&supps, sizeof(SUPPLY), 1, bpsupps);
	
	if (number == supps.snum) {
		printf("Supplier Number: %d\n", supps.snum);
  		printf("Supplier Name: %s\n", supps.sname);
  		printf("Supplier Address: %s\n", supps.sadd);
  		printf("Supplier Contact: %s", supps.scontact);
  		printf("\nDo you want to edit?\n");
  		scanf("%c", &answer);
		if (answer == 'Y' || answer == 'y'){
			printf("\n\nPress 1 to change the name\n");
			printf("Press 2 to change the address\n");
			printf("Press 3 to change the contact");
			printf("Choice: ");
			scanf("%d", &choice);
			if (choice == 1) {
				fflush(stdin);
				printf("Enter new name: ");
				gets(suppname);
				strcpy(supps.sname, suppname);
			}
			if (choice == 2) {
				fflush(stdin);
				printf("Enter new address: ");
				gets(suppadd);
				strcpy(supps.sadd, suppadd);
			}
			if (choice == 3) {
				fflush(stdin);
				printf("Enter new contact: ");
				gets(suppcontacts);
				strcpy(supps.scontact, suppcontacts);
			}
			fseek(bpsupps, number*sizeof(SUPPLY), 0);
			fwrite(&supps, sizeof(SUPPLY), 1, bpsupps);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("Record not here...");
	getch();
	fclose(bpsupps);
}

void DeleteSupps(FILE *bpsupps, SUPPLY supps){
    int  number, response, flag=0;

	bpsupps = fopen("supply.dat", "r+b");
	system("cls");
	printf("Enter Supply Number:");
	scanf("%d", &number);
	fseek(bpsupps, number*sizeof(SUPPLY), 0);
	fread(&supps, sizeof(SUPPLY), 1, bpsupps);
	if (number == supps.snum) {
		printf("Supplier Number: %d\n", supps.snum);
  		printf("Supplier Name: %s\n", supps.sname);
  		printf("Supplier Address: %s\n", supps.sadd);
  		printf("Supplier Contact: %s", supps.scontact);
		printf("\n\nDELETE this record? (Y/N): ");
		scanf(" %c", &response);
		if (toupper(response) == 'Y') {
			supps.snum = 0;
			strcpy(supps.sname, "");
			strcpy(supps.sadd, "");
			strcpy(supps.scontact, "");
			fseek(bpsupps, number*sizeof(SUPPLY), 0);
			fwrite(&supps, sizeof(SUPPLY), 1, bpsupps);
			flag = 1;
		}
		else {
			printf("DELETION ABORTED...Press any key to continue.");
			getch();
		}
	}
	if (flag == 0)
		printf("Record not here...");
	getch();
	fclose(bpsupps);
     
}

void DisplaySupps(FILE *bpsupps, SUPPLY supps){
	int i, y=4;

	bpsupps = fopen("supply.dat", "rb");
	system("cls");
	printf("Supply Number      Supply Name            Supply Address            Supply Contact");

	for (i=0; i<20; i++) {
		fseek(bpsupps, i*sizeof(SUPPLY), 0);
		fread(&supps, sizeof(SUPPLY), 1, bpsupps);
			gotoxy(1, y); printf("%d", supps.snum);
			gotoxy(20, y); printf("%s", supps.sname);
			gotoxy(50, y); printf("%s", supps.sadd);
			gotoxy(70, y); printf("%s", supps.scontact);
			y++;
	}
	getch();
}

//adding sales data
void SalesGro(int p, int *add3, FILE *bptrans,  FILE *bp, SALES sals, ITEM itm){
	int number;
	int salesid,salesdate, quantity;
	float salssubtots;
	int count4 = p;
	system("cls");
	//searching item data number
  	bp = fopen("item.dat", "r+b");
  	printf("Enter Item Number:");
  	scanf("%d",&number);
  	fseek(bp, number*sizeof(ITEM), SEEK_SET);
  	fread(&itm, sizeof(ITEM), 1, bp);
  	if (itm.id == number){
  		//if item number existed
  		bptrans = fopen("sales.dat", "r+b");
  		fseek(bptrans, salesid*sizeof(SALES), SEEK_SET);
  		fread(&sals, sizeof(SALES), 1, bptrans);
  		printf("Enter Sales Number: ");
		scanf("%d", &salesid);
		//if sales number already existed
		if (SalesNumber(salesid) != 1){
        	printf("\nInvalid item number. Number already taken!\n");
    	}
    	else{
    		printf("Enter Sales date: ");
			scanf("%d", &salesdate);
			printf("Enter Quantity Bought: ");
			scanf("%d", &quantity);
			sals.transno = salesid;
			sals.date=salesdate;
			sals.quant = quantity;
			sals.itemno = number;
			sals.price = itm.price * sals.quant;//adding the sales price
			itm.itemsoh--;//decreasing stock on hand
			printf("Record added. Press any key to continue.");
			getch();
		}
	}

  	else
	  	printf("Item number is not existing...");
  	getch();
  	fseek(bp, number*sizeof(ITEM),SEEK_SET);
	fwrite(&itm,sizeof(ITEM),1,bp);
	fseek(bptrans, salesid*sizeof(SALES),SEEK_SET);
	fwrite(&sals,sizeof(SALES),1,bptrans);
	fclose(bp);
  	fclose(bptrans);
  	count4++;
	*add3 = count4;
}

//display sales
void DisplaySales(FILE *bptrans, SALES sals){
	int i, y=4;

	bptrans = fopen("sales.dat", "rb");
	system("cls");
	printf("Sales Number      Sales Date            Sales Item No.            Sales Quantity            Sales Subtotal");

	for (i=0; i<20; i++) {
		fseek(bptrans, i*sizeof(SALES), 0);
		fread(&sals, sizeof(SALES), 1, bptrans);
			gotoxy(1, y); printf("%d", sals.transno);
			gotoxy(20, y); printf("%d", sals.date);
			gotoxy(50, y); printf("%d", sals.itemno);
			gotoxy(70, y); printf("%d", sals.quant);
			gotoxy(90, y); printf("%.2f", sals.price);
			y++;
	}
	getch();
}
//getting purchase data
void PurchaseGro(int q, int *add4, FILE *bppurch, FILE *bp, FILE *bpsupps, PURCHASE purch, ITEM itm, SUPPLY supps){
	int number, supnumber;
	int purnum, purdate, quantitypurch;
	float purchsubtots, cost, per;
	int count5 = q;
	system("cls");
  	bp = fopen("item.dat", "r+b");
  	bpsupps = fopen("supply.dat", "rb");
  	//opening the supply and item number
  	printf("Enter Item Number:");
  	scanf("%d",&number);
  	printf("\nEnter Supplier Number: ");
  	scanf("%d", &supnumber);
  	//reading data
  	fseek(bp, number*sizeof(ITEM), SEEK_SET);
  	fread(&itm, sizeof(ITEM), 1, bp);
  	fseek(bpsupps, supnumber*sizeof(SUPPLY), SEEK_SET);
  	fread(&supps, sizeof(SUPPLY), 1, bpsupps);
  	
  	if (itm.id == number && supps.snum == supnumber){
  		//if item number and supplier number already existed
  		bppurch = fopen("purchase.dat", "r+b");
  		fseek(bppurch, purnum*sizeof(PURCHASE), SEEK_SET);
  		fread(&purch, sizeof(PURCHASE), 1, bppurch);
  		printf("Enter Purchase Number: ");
		scanf("%d", &purnum);
		//if purchase number is already existed in the data
		if (PurchNumber(purnum) != 1){
        	printf("\nInvalid item number. Number already taken!\n");
    	}
		else{
			printf("Enter Purchase date: ");
			scanf("%d", &purdate);
			printf("Enter Unit Cost: ");
			scanf("%f", &cost);
			printf("Enter Quantity Purchased: ");
			scanf("%d", &quantitypurch);
			purch.itemno = number;
			purch.snum = supnumber;
			purch.pno = purnum;
			purch.date = purdate; 
			purch.unitcost = cost;
			purch.qtypurch = quantitypurch;
			purch.subtotal = purch.unitcost * purch.qtypurch; //to get the subtotal
			per = purch.unitcost * 0.05;
			itm.price = itm.price + per; //to change the item price
			itm.itemsoh++; //incresing the item stock on hand
			printf("Record added. Press any key to continue.");
			getch();
			fseek(bppurch, purnum*sizeof(PURCHASE),SEEK_SET);
			fwrite(&purch,sizeof(PURCHASE),1,bppurch);
		}
	}

  	else if ((number != itm.id) || (supnumber == supps.snum))
	  	printf("One is existing...");
	else 
	  	printf("Both Records didn't exist...");
	
	if (purch.pno == purnum){
		printf("The number is already occupied. Enter Another Number");
	}
  	getch();
  	fseek(bp, number*sizeof(ITEM),SEEK_SET);
	fwrite(&itm,sizeof(ITEM),1,bp);
	fseek(bp, supnumber*sizeof(SUPPLY),SEEK_SET);
	fwrite(&supps,sizeof(SUPPLY),1,bp);
	fclose(bp);
	fclose(bpsupps);
  	fclose(bppurch);
  	count5++;
	*add4 = count5;
}

void DisplayPurchase(FILE *bppurch, PURCHASE purch){
	int i, y=4;

	bppurch = fopen("purchase.dat", "rb");
	system("cls");
	printf("Purchase Number      Purchase Date            Supplier No.            Item No.            Unit Cost            Quantity Purchased            Subtotal");

	for (i=0; i<20; i++) {
		fseek(bppurch, i*sizeof(PURCHASE), 0);
		fread(&purch, sizeof(PURCHASE), 1, bppurch);
			gotoxy(1, y); printf("%d", purch.pno);
			gotoxy(20, y); printf("%d", purch.date);
			gotoxy(50, y); printf("%d", purch.snum);
			gotoxy(70, y); printf("%d", purch.itemno);
			gotoxy(90, y); printf("%.2f", purch.unitcost);
			gotoxy(110, y); printf("%d", purch.qtypurch);
			gotoxy(130, y); printf("%.2f", purch.subtotal);
			y++;
	}
	getch();
}

void gotoxy(short x, short y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
