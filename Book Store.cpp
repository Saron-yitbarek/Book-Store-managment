//book store

#include <iostream>
#include<stdlib.h>
#include <fstream>
#include<cstring>
using namespace std;

struct userr{
char name[20];
char nuser[20];
char  password[10];
float npassword;
} ;
      struct userList{
              userr *uList;
              int s;
              int uavailable;
                             };

                    struct bookk{

                         float id;
                         float isbn;
                        char title[40];
                        int date;
                        int month;
                        int year;
                        char category[40];
                        char publisher[40];
                        int edition;
                        int copies;
                        int pages;
                        float price;
                        float discount;
                                            };
struct bList{
    bookk * booklist;
    int n;
    int bavailable;
};


struct sale{
int invoiceNo;
int date;
char name[20];
int bookId;
int quantity;
};

struct cList{
    sale * list;
    int c;
    int cavail;
};
void manageuser(fstream &user,userList &ul,userr us);
void removeDeleted(fstream &user, char *path);
void Remove(fstream & user,userList ul , int targetIdx);
void display(userList ul);
enum ERROR{INSUFFICIENT_MEMORY,USER_NOT_MODIFIED, USER_NOT_FOUND, FILE_OPEN_FAILED };
void edit(fstream & user, userList ul, int targetIdx, userr us);
void display(userr us);
void display(userr us);
int searchByName(userList ul, char target[20]);
int getUserEdited(userr & olduser);
 void getName(char  target[20]);
void admin(fstream &user,userList &ul,userr us);
long fileSize(fstream & user);
int add(fstream & user, userList & ul, userr us);
void adduser(userr&us);
int resize(userList & ul,int n);
void login(fstream &user,userList &ul,userr us);
void authenticationboard(fstream &user,userList &ul,userr us);
int openFile(fstream & user, char * path);
int userallocate( userList &ul, int n);
void landingboard(int &c);
void landmenu(fstream &user,int c,userList&ul);
int loading(fstream & user, char * path,  userList &ul);
const userr BLANK_STUDENT={"",-1};
const bookk BLANK_BOOK={-1,-1,"",-1,-1,-1,"","", -1.-1,-1,-1,-1};
int allocate( bList &bl, int n);
bookk getBook();
void managebook();
int addbook(fstream & book, bList & bl, bookk b);
int resizebook(bList & bl,int n);
void editbook(fstream & book, bList bl, int targetIdx, bookk b);
void editbook(fstream & book, bList bl, int targetIdx,bookk b);
void Removebook(fstream & book,  bList bl, int targetIdx);
int searchById( bList bl, int target);
int openFilebook(fstream & book, char * path);
int loadingbook(fstream & book, char * path, bList &bl);
int menu();
long fileSizebook(fstream & ifs);
int getId();
int getBookEdited(bookk & oldBook);
void displaybook( bList bl);
void displaybook(bookk  oldBook);
enum BookERROR{INSUFFICIENTBOOK_MEMORY,BOOK_NOT_MODIFIED, BOOK_NOT_FOUND, BOOKFILE_OPEN_FAILED };
void errorbook(BookERROR errID);
void removeDeletedbook(fstream &book, char *path);
 int allocate(bList&, int );
void error(ERROR errID);const sale BLANK_CHASHIER={-1, -1,"",-1,-1};
long fileSizeCHASHIER(fstream & chashier);
enum ERRORCHASHIER{INSUFFICIENTCHASHIER_MEMORY,CHASHIER_NOT_MODIFIED, CHASHIER_NOT_FOUND, CHASHIERFILE_OPEN_FAILED};
void editCHASHIER(fstream & chashier, cList cl, int targetIdx, sale s);
void displayCHASHIER(sale s);
void displayCHASHIER(cList cl);
void removeDeletedCHASHIER(fstream &chashier, char *path);
void viewSale(sale s,cList cl);
void RemoveCHASHIER(fstream & chashier, cList cl, int targetIdx);
void editCHASHIER(fstream & chashier, cList cl, int targetIdx, sale s);
int searchByIdCHASHIER(cList cl, int target);
void errorCHASHIER(ERRORCHASHIER errID);
int loadingCHASHIER(fstream & chashier, char * path,cList & cl);
int addCHASHIER(fstream & chashier, cList & cl, sale s);
sale newSale();
int cashierMenu();
void saleOrder(fstream & chashier, cList & cl, sale s);
int saleOrderMenu();
int getSaleEdited(sale &oldsale);
int getIdCHASHIER();
int managechashier();


int main(){
    int c;
    fstream user;
    userList ul;
    ul.uList=NULL;
    ul.s=0;
    ul.uavailable=0;
    userr us;
    int cheker;
     char ch;
    cout<<"                                          SYN BOOK MANAGMENT SYSTEM"<<endl;
   cout<<endl;
    cout<<"  Welcome to our book management system do you want to add a new user(y/n)"<<endl;
    cin>>ch;
            if(ch=='y' or ch=='Y'){
                     adduser(us);
                      add(user,ul,us);}

                           else if(ch=='n' or ch=='N'){
                                cheker==-1;}

cheker=loading(user,"user.bin",ul);

    if (cheker==1 or cheker==-1){
landingboard(c);
landmenu(user,c,ul);}
            else if(cheker==0){
                  error(FILE_OPEN_FAILED);
                     system("pause");
                            }
                             else{
                                error(INSUFFICIENT_MEMORY);
                                            system("pause");}

system("pause");
}

int openFile(fstream & user, char * path){
    user.open(path, ios::in | ios::out | ios::binary);
    if(user.is_open()){
        return 1;
    }
        else{
            return 0;
        }
    }


int userallocate( userList &ul, int n){
    ul.uList=new (nothrow) userr[n];
   if(ul.uList==NULL){
        return 0;
    }else{
        ul. s=0;
        ul.uavailable=n;
        return 1;
    }

}
long fileSize(fstream & user){
    if(user){
        user.seekg(0, ios::end);
        return user.tellg();
    }else
        return -1;
}
int loading(fstream & user, char * path, userList &ul){
    int n;
    user.close();
    userr u;
    user.open(path);
    if(user.is_open()){
        n=fileSize(user)/sizeof(userr);
        if(userallocate(ul,n+10)){
            user.seekg(0, ios::beg);
            for(int i=0; i<n; i++){
                user.read((char *)&u, sizeof(u));
                ul.uList[i]=u;
            }
            ul.uavailable=10;
            ul.s=n;
            return 1;
        }else{
            return 2;
        }
    }else{
   ofstream os(path);
   os.close();
   user.close();
   return loading(user,path,ul);
    }

}
void landingboard(int &c){
cout<<"Welcome "<<endl;
cout<<"1) Admin"<<endl;
cout<<"2) Cashier"<<endl;
cout<<"3) Exit"<<endl;
cin>>c;
system("cls");


}
void landmenu(fstream &user,int c,userList &ul){
 userr us;

if(c==1)
  authenticationboard  (user,ul,us);

else if(c==2)
    managechashier();
else{system("pause");}


}
void authenticationboard(fstream &user,userList &ul,userr us){
int ch;
cout<<"1)Login "<<endl;
cout<<"2)Exit"<<endl;
cin>>ch;

    if (ch==1){
       login(user,ul,us);}

                 else
                   cout<<"error";
}

void login(fstream &user,userList &ul,userr us){
    int m;
char name[20];
char password[10];
while(true){
cout<<"Enter your User Name "<<endl;
cin>>name;
cout<<"Enter your Password   "<<endl;
cin>>password;
system("cls");
for(int i=0; i<ul.s; i++){
        if(strcmp(ul.uList[i].name,name)==0&& strcmp(ul.uList[i].password,password )==0){
            cout<<"You have logged in successfully!!!"<<endl;
            admin(user,ul,us);
        }

    }

cout<<"You have inputed the wrong password or user name please try again!!!"<<endl;

authenticationboard(user,ul,us);
}

}
void adduser(userr &us){
    cout<<"Write new user name "<<endl;
    cin>>us.name;
    cout<<"Write new password"<<endl;
    cin>>us.password;
    cout<<"YOU HAVE SUCUESSFULLY ADDED A USER"<<endl;


}
int resize(userList & ul,int n){
    userr * tmp;
    tmp=new (nothrow) userr[ul.s + n];
    if(tmp==NULL) return 0;
    for(int i=0; i<ul.s; i++)
        tmp[i]=ul.uList[i];
    delete [] ul.uList;
    ul.uList=tmp;
    ul.uavailable=n;
    return 1;
}
int add(fstream & user, userList & ul, userr us){
    user.open("user.bin");
    if(user.is_open()==false){
    ofstream os("user.bin");
    os.close();
    user.close();
   user.open("user.bin");
    }

    if(  ul.uavailable==0){
        if(!resize(ul,10)) {
            cout<<"unsuccessful"<<endl;
        }}
    user.seekp(0,ios::end);
    user.write((char *)&us, sizeof(us));
    user.flush();
   user.close();
 return 1;

}
void admin(fstream &user,userList &ul,userr us){

int cho;
cout<<"Enter what you want to do"<<endl;
cout<<"1)Manage User"<<endl;
cout<<"2)Manage Book"<<endl;
cout<<"3)Report"<<endl;
cout<<"4)Back To Authentication "<<endl;
cout<<"5)Exit"<<endl;
cin>>cho;
system("cls");
if(cho==1)
    manageuser(user,ul,us);
    else if(cho==2)
        managebook();
        else if (cho==4)
          authenticationboard(user,ul,us);
    }
    void managebook(){
        int choice;
    fstream book;
    fstream user;
    userList ul;
    userr us;
    bList bl;
    bl.booklist=NULL;
    bl.n=0;
    bl.bavailable=0;
    bookk b;
    int id, idx,status;
    status=loadingbook(book,"book.bin",bl);
    if(status==1){
    do{
            choice=menu();
            switch(choice){
                case 1:
                    b=getBook();
                    if(!addbook(book,bl,b))
                        errorbook(INSUFFICIENTBOOK_MEMORY);
                    break;
                case 2:
                    id=getId();
                    idx=searchById(bl,id);
                    if(idx>=0){
                        b=bl.booklist[idx];
                        if(getBookEdited(b))
                            editbook(book,bl,idx,b);
                        else{
                            errorbook(BOOK_NOT_MODIFIED);
                        }
                    }else
                        errorbook(BOOK_NOT_FOUND);

                    break;
                case 3:
                    id=getId();
                    idx=searchById(bl,id);
                    if(idx>=0){
                        Removebook(book,bl,idx);
                    }else
                         errorbook(BOOK_NOT_FOUND);
                    break;
                case 4:
                    id=getId();
                    idx=searchById(bl,id);
                    if(idx>=0)
                        displaybook(bl.booklist[idx]);
                    else
                        errorbook(BOOK_NOT_FOUND);
                    break;
                case 5:
                    displaybook(bl);
                    break;
                case 6:
                    admin(user,ul,us);
                    break;
                case 7:
                    removeDeletedbook(book,"book.bin");
                    break;
            }
            system("pause");
        }while(choice != 7);
        }else if(status==0){
        errorbook(BOOKFILE_OPEN_FAILED);
        system("pause");
    }else{
        errorbook(INSUFFICIENTBOOK_MEMORY);
        system("pause");
    }
}

    void manageuser(fstream &user,userList &ul,userr us){
    int choice;
    char target[20];
      userr uu;

      do{
            system("cls");
    cout<<"Enter what you want"<<endl;
    cout<<"1)Add User "<<endl;
     cout<<"2)Update User "<<endl;
      cout<<"3)Delete User "<<endl;
       cout<<"4)Search User by Name "<<endl;
        cout<<"5)View all Users "<<endl;
        cout<<"6)Back To Admin Main Board "<<endl;
         cout<<"7)Exit "<<endl;
         cin>>choice;
         system("cls");
         int idx;
    switch(choice){
                case 1:
                    adduser(us);
                       add(user,ul,us);
                    break;
                case 2:
                    getName(target);
                    idx=searchByName(ul,target);
                    if(idx>=0){
                        us=ul.uList[idx];
                        if(getUserEdited(us))
                            edit(user,ul,idx,us);
                        else{
                            error(USER_NOT_MODIFIED);
                        }
                    }else
                        error(USER_NOT_FOUND);

                    break;
                case 3:
                   getName(target);
                    idx=searchByName(ul,target);
                    if(idx>=0){
                        Remove(user,ul,idx);
                    }else
                         error(USER_NOT_FOUND);
                    break;
                case 4:
                    getName(target);
                    idx=searchByName(ul,target);
                    if(idx>=0)
                        display(ul.uList [idx]);
                    else
                        error(USER_NOT_FOUND);
                    break;
                case 5:
                    display(ul);
                    break;
                case 6:
                    admin(user,ul,us);
                    break;
                case 7:
                    removeDeleted(user,"user.bin");
                    break;

            }
            system("pause");
        }while(choice != 6);




    }
    void getName(char  target[20]){

    cout << "Enter the user name: ";
    cin>>target;

}
int searchByName(userList ul, char target[20]){

    for(int i=0; i<ul.s; i++){
        if(strcmp(ul.uList[i].name,target)==0){

            return i;
        }}


   return -1;

}

int getUserEdited(userr & olduser){
    int choice;
    int status=0;
    do{
        system("cls");
        cout << "User "<<endl;
        display(olduser);
        cout <<endl;
        cout << "Which field you want to edit: "<<endl;
        cout<<"1. User Name"<<endl;
        cout<<"2. password"<<endl;
        cout<<"3. Finished Editing"<<endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout <<"Enter New User Name: ";
                cin>>olduser.name;
                status=1;
                break;
            case 2:
                cout <<"Enter New Password: ";
                cin>>olduser.password;
                status=1;
                break;

            case 3:
                break;
            default:
                cout <<"Wrong choice!!!"<<endl;
                system("pause");
                break;
        }

    }while(choice!=3);
     system("pause");
     return status;
}
void display(userr us){
    cout <<"User Name " <<us.name<<endl;
    cout <<"Password: " <<us.password<<endl;

}

void edit(fstream & user, userList ul, int targetIdx, userr us){
        ul.uList[targetIdx]=us;
        user.seekp(targetIdx*sizeof(us), ios::beg);
        user.write((char *)&us, sizeof(us));
}
void Remove(fstream & user,userList ul , int targetIdx){
    edit(user,ul,targetIdx,BLANK_STUDENT);
}
void display(userList ul){
    int n=1;
    for(int i=0; i< ul.s ; i++){

            cout << "#" << n<<" User"<<endl;
            display(ul.uList[i]);
            cout <<endl;
            n++;

    }
}
void removeDeleted(fstream &user, char *path){
    userr us;
    ofstream ofs("temp.bin",ios::out|ios::binary);
    int no=fileSize(user)/sizeof(us),i=0;
    user.seekg(0,ios::beg);
    while(i<no){
        user.read((char *)&us, sizeof(us));

            ofs.write((char *)&us,sizeof(us));
            ofs.flush();

		i++;
    }
    user.close();
    remove(path);
    ofs.close();
    rename("temp.bin",path);
}
void error(ERROR errID){
    switch(errID){
        case INSUFFICIENT_MEMORY:
            cout << "The system doesn't have enough memory!"<<endl;
            break;
        case USER_NOT_FOUND:
            cout << "Student not found in the database!"<<endl;
            break;
        case FILE_OPEN_FAILED:
            cout << "Unable to open the file!"<<endl;
            break;
        case USER_NOT_MODIFIED:
            cout << "Student is not modified!"<<endl;
            break;
    }
}
int allocate(  bList &bl, int n){
    bl.booklist=new (nothrow) bookk[n];
    if(bl.booklist==NULL){
        return 0;
    }else{
        bl.n=0;
        bl.bavailable=n;
        return 1;
    }

}
int getId(){
    int id;
    cout << "Enter the student id: ";
    cin>>id;
    return id;
}


bookk getBook(){
    bookk b;
    cout<<"Enter student information"<<endl;

   cout<<"Enter the id of the author (USE ONLY NUMERICAL CHARACTER)"<<endl;
    cin>>b.id;
    cout<<"Enter the unique commercial book identifier(USE ONLY NUMERICAL CHARACTER) "<<endl;
    cin>>b.isbn;
    cout<<"Enter  the title of the book"<<endl;
    cin>>b.title;
    cout<<"Enter  the date for the book to be published date in this form (date month year) and(USE ONLY NUMERICAL CHARACTER) "<<endl;
    cin>>b.date>>b.month>>b.year;
    cout<<"Enter the book category"<<endl;
    cin>>b.category;
    cout<<"Enter the company that publish the book"<<endl;
    cin>>b.publisher;
    cout<<"Enter the edition number (USE ONLY NUMERICAL CHARACTER)"<<endl;
    cin>>b.edition;
    cout<<"Enter the copies of the book available (USE ONLY NUMERICAL CHARACTER)"<<endl;
    cin>>b.copies;
    cout<<"Enter the no of pages in the book (USE ONLY NUMERICAL CHARACTER)"<<endl;
    cin>>b.pages;
    cout<<"Enter the selling price of the book (USE ONLY NUMERICAL CHARACTER)"<<endl;
    cin>>b.price;
    cout<<"Enter the discount is there is any (USE ONLY NUMERICAL CHARACTER)"<<endl;
    cin>>b.discount;
    return b;
}
int getBookEdited(bookk & oldBook){
    int choice;
    int status=0;
    do{
        system("cls");
        cout << "Book "<<endl;
        displaybook(oldBook);
        cout <<endl;
        cout << "Which field you want to edit: "<<endl;
        cout<<"1.The ID of the book"<<endl;
       cout<<"2.The title of the book"<<endl;
        cout<<"3.The published date"<<endl;
        cout<<"4.The category of the book"<<endl;
        cout<<"5.The company that published the book"<<endl;
        cout<<"6.The edition number"<<endl;
        cout<<"7.The copies available"<<endl;
       cout<<"8.The number of pages"<<endl;
        cout<<"9.The price of the book"<<endl;
        cout<<"10.The discount of the book"<<endl;

        cout<<"11. Finished Editing"<<endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout <<"Enter the new id: ";
                cin>>oldBook.id;
                status=1;
                break;
            case 2:
                cout <<"Enter the new title: ";
                cin>>oldBook.title;
                status=1;
                break;
            case 3:
                cout <<"Enter the new published date: ";
                cin>>oldBook.date>>oldBook.month>>oldBook.year;
                status=1;
                break;
            case 4:
                cout <<"Enter the new category of the book: ";
                cin>>oldBook.category;
                status=1;
                break;
            case 5:
                cout <<"Enter the new company that published the book ";
                cin>>oldBook.publisher;
                status=1;
                break;
            case 6:
                cout << "Enter the new edition number: ";
                cin>>oldBook.edition;
                status=1;
                break;
             case 7:
                cout << "Enter the new copies left: ";
                cin>>oldBook.copies;
                status=1;
                break;
            case 8:
                cout << "Enter the new pages: ";
                cin>>oldBook.pages;
                status=1;
                break;
            case 9:
                cout << "Enter the new price: ";
                cin>>oldBook.price;
                status=1;
                break;
            case 10:
                cout << "Enter the new discount: ";
                cin>>oldBook.discount;
                status=1;
                break;
            case 11:
                break;
            default:
                cout <<"Wrong choice!!!"<<endl;
                system("pause");
                break;
        }

    }while(choice!=11);
     system("pause");
     return status;
}
int resizebook(bList & bl,int n){
    bookk * tmp;
    tmp=new (nothrow) bookk[bl.n + n];
    if(tmp==NULL) return 0;
    for(int i=0; i<bl.n; i++)
        tmp[i]=bl.booklist[i];
    delete [] bl.booklist;
   bl.booklist=tmp;
    bl.bavailable=n;
    return 1;
}
int addbook(fstream & book, bList & bl, bookk b){
    if(bl.bavailable==0)
        if(!resizebook(bl,10)) return 0;
    book.seekp(0,ios::end);
    book.write((char *)&b, sizeof(b));
    book.flush();
    bl.booklist[bl.n]=b;
     bl.n++;
    bl.bavailable--;
    return 1;
}
void editbook(fstream & book, bList bl, int targetIdx, bookk b){
         bl.booklist[targetIdx]=b;
        book.seekp(targetIdx*sizeof(b), ios::beg);
      book.write((char *)&b, sizeof(b));
}
void Removebook(fstream & book, bList bl, int targetIdx){
    editbook(book,bl,targetIdx,BLANK_BOOK);
}
int searchById(bList bl, int target){
    for(int i=0; i<bl.n; i++){
        if(bl.booklist[i].id==target){
            return i;
        }

    }
    return -1;

}

int openFilebook(fstream & book, char * path){
    book.open(path, ios::in | ios::out | ios::binary);
    if( book.is_open()){
        return 1;
    }else{
        ofstream ofs(path, ios::out | ios::binary);
        if(ofs){
            ofs.close();
             book.open(path, ios::in | ios::out | ios::binary);
            return 1;
        }else{
            return 0;
        }
    }

}

int loadingbook(fstream &  book, char * path,bList & bl){
    int n;
    bookk b;
    if(openFilebook( book,path)){
        n=fileSizebook( book)/sizeof(bookk);
        if(allocate(bl,n+10)){
             book.seekg(0, ios::beg);
            for(int i=0; i<n; i++){
                 book.read((char *)&b, sizeof(b));
             bl.booklist[i]=b;
            }
           bl.bavailable=10;
            bl.n=n;
            return 1;
        }else{
            return 2;
        }
    }else
        return 0;
}
long fileSizebook(fstream &  ifs){
    if(ifs){
        ifs.seekg(0, ios::end);
        return ifs.tellg();
    }else
        return -1;
}
int menu(){
    int choice;
    do{
        system("cls");
        cout<<"Enter what you want"<<endl;
    cout<<"1)Register Book "<<endl;
     cout<<"2)Update Book "<<endl;
      cout<<"3)Delete Book "<<endl;
       cout<<"4View Book by serach "<<endl;
        cout<<"5)View All "<<endl;
         cout<<"6)Exit "<<endl;
        cin >> choice;
        system("cls");
        if(choice <1 || choice >6){
            cout << "Invalid menu choice!"<<endl;
            system("pause");
        }
    }while(choice <1 || choice >6);
    return choice;

}
void displaybook(bookk b){
    cout <<"The ID of the book:           "<<b.id<<endl;
       cout<<"The title of the book:           "<<b.title<<endl;
        cout<<"The published date:        "<<b.date<<"/"<<b.month<<"/"<<b.year<<"/"<<endl;
        cout<<"The category of the book:     "<<b.category<<endl;
        cout<<"The company that published the book:       "<<b.publisher<<endl;
        cout<<"The edition number:       "<<b.edition<<endl;
        cout<<"The copies available:        "<<b.copies<<endl;
       cout<<"The number of pages:         "<<b.pages<<endl;
        cout<<"The price of the book:        "<<b.price<<endl;
        cout<<"The discount of the book:        "<<b.discount<<endl;

}
void displaybook(bList bl){
    int n=1;
    for(int i=0; i< bl.n; i++){

            cout << "#" << n<<" book"<<endl;
            displaybook(bl.booklist[i]);
            cout <<endl;
            n++;

    }
}

void errorbook(BookERROR errID){
    switch(errID){
        case INSUFFICIENTBOOK_MEMORY:
            cout << "The system doesn't have enough memory!"<<endl;
            break;
        case BOOK_NOT_FOUND:
            cout << "Book not found in the database!"<<endl;
            break;
        case BOOKFILE_OPEN_FAILED:
            cout << "Unable to open the file!"<<endl;
            break;
        case BOOK_NOT_MODIFIED:
            cout << " Book is not modified!"<<endl;
            break;
    }
}
void removeDeletedbook(fstream & book, char *path){
    bookk b;
    ofstream ofs("temp.bin",ios::out|ios::binary);
    int noOfBook=fileSizebook( book)/sizeof(b),i=0;
     book.seekg(0,ios::beg);
    while(i<noOfBook){
        book.read((char *)&b, sizeof(b));
        if(b.id>=0){
            ofs.write((char *)&b,sizeof(b));
            ofs.flush();
    	}
		i++;
    }
    book.close();
    remove(path);
    ofs.close();
    rename("temp.bin",path);
}
int managechashier()
{

    int choice;
    fstream chashier;
   int c;
    cList cl;
    cl.list=NULL;
    cl.c=0;
    cl.cavail=0;
    sale s;
    int id, idx,status;
    status=loadingCHASHIER(chashier,"chashier.bin",cl);
    if(status==1){

  choice=cashierMenu();
  switch(choice){
  case 1:
      saleOrder(chashier,cl,s);
  case 5 :
    landingboard(c);
  }

    }

}
int cashierMenu()
{
    int choice;
    do{
    cout<<"1. Manage Sale order\n2.Manage Purchase Order\n3. Report\n4.Back to admin\n5.Exit\nChoice: ";
    cin>>choice;
     if(choice <1 || choice >6){
            cout << "Invalid menu choice!"<<endl;
            system("pause");
        }
    }while(choice <1 || choice >6);
    return choice;
}
void saleOrder(fstream & chashier, cList & cl, sale s)
{

    int idx;
    int id;
    int saleOrderMenuChoice;

    system("cls");
    do{
    saleOrderMenuChoice=saleOrderMenu();

    if(saleOrderMenuChoice==1){
       s= newSale();
       if(!addCHASHIER(chashier,cl,s))
                        errorCHASHIER(INSUFFICIENTCHASHIER_MEMORY);}

    if (saleOrderMenuChoice==2){
        id=getIdCHASHIER();
                    idx=searchByIdCHASHIER(cl,id);
                    if(idx>=0){
                        s=cl.list[idx];
                        if(getSaleEdited(s))
                            editCHASHIER(chashier,cl,idx,s);
                        else{
                            errorCHASHIER(CHASHIER_NOT_MODIFIED);
                        }
                    }else
                        errorCHASHIER(CHASHIER_NOT_FOUND);
    }


    if (saleOrderMenuChoice==3){
        id=getIdCHASHIER();
                    idx=searchByIdCHASHIER(cl,id);
                    if(idx>=0){
                        RemoveCHASHIER(chashier,cl,idx);
                    }else
                         errorCHASHIER( CHASHIER_NOT_FOUND);}


    if (saleOrderMenuChoice==4)
        viewSale( s, cl);
    if (saleOrderMenuChoice==5)
        cashierMenu();
    if (saleOrderMenuChoice==6)
        removeDeletedCHASHIER(chashier,"chashier.bin");
        if(saleOrderMenuChoice <1 || saleOrderMenuChoice >6){
            cout << "Invalid menu choice!"<<endl;
            system("pause");
        }
        }while(saleOrderMenuChoice <1 || saleOrderMenuChoice >6);
}
int saleOrderMenu()
{
    int choice;
    cout<<"1.New Sale\n2.Update Sale\n3.Delete Sale\n4.View Sale\n5.Back to Main Cashier Board\n6.Exit\nChoice: ";
    cin>>choice;
    return choice;
}
sale newSale()
{
    sale s;

cout<<"Enter customer Name: ";

    cin>>s.name;


    cout<<"Enter date: ";
    cin>>s.date;

    cout<<"Enter the bookID: ";
    cin>>s.bookId;
    cin.ignore();
    cout<<"Enter quantity: ";
    cin>>s.quantity;
    system("cls");

   cout<<"The Reciept "<<endl;
    cout<<"User name: "<<s.name<<endl;
    cout<<"Date of purchase: "<<s.date<<endl;
    cout<<"BookId: "<<s.bookId<<endl;
    cout<<"Quantity: "<<s.quantity<<endl;

    return s;


}
int getSaleEdited(sale &oldsale){
int choice;
int status=0;
do{
        system("cls");
        cout << "Sale "<<endl;
        displayCHASHIER(oldsale);
        cout <<endl;
        cout << "Which field you want to edit: "<<endl;
        cout<<"1) User name"<<endl;
        cout<<"2) Date of purchase"<<endl;
        cout<<"3) BookId"<<endl;
        cout<<"4)InvoiceNo"<<endl;
        cout<<"5) Quantity"<<endl;
        cout<<"6) Finished editing"<<endl;

        cin>>choice;
        switch (choice){
    case 1:
        cout<<"Enter the new name"<<endl;
        cin>>oldsale.name;
        status=1;
        break;
    case 2:
        cout<<"Enter the new Date of Purchase"<<endl;
        cin>>oldsale.date;
        status=1;
        break;
   case 3:
        cout<<"Enter the new book ID"<<endl;
        cin>>oldsale.bookId;
        status=1;
        break;
   case 4:
        cout<<"Enter the new InvoiceNo"<<endl;
        cin>>oldsale.invoiceNo;
        status=1;
        break;
    case 5:
        cout<<"Enter the new quantity"<<endl;
        cin>>oldsale.quantity;
        status=1;
        break;
    case 6:
                break;
            default:
                cout <<"Wrong choice!!!"<<endl;
                system("pause");
                break;
        }

}while(choice!=6);
     system("pause");

     return status;
     }


void displayCHASHIER(sale s){
 cout<<"User name: "<<s.name<<endl;
    cout<<"Date of purchase: "<<s.date<<endl;
    cout<<"BookId: "<<s.bookId<<endl;
    cout<<"Quantity: "<<s.quantity<<endl;


}
int getIdCHASHIER(){
int id;
cout<<"Enter the id"<<endl;
cin>>id;
return id;

}
int searchByIdCHASHIER(cList cl, int target){
    for(int i=0; i<cl.c; i++){
        if(cl.list[i].bookId==target){
            return i;
        }

    }
    return -1;

}
void RemoveCHASHIER(fstream & chashier, cList cl, int targetIdx){
    editCHASHIER(chashier,cl,targetIdx,BLANK_CHASHIER);
}
void editCHASHIER(fstream & chashier, cList cl, int targetIdx, sale s){
        cl.list[targetIdx]=s;
        chashier.seekp(targetIdx*sizeof(s), ios::beg);
        chashier.write((char *)&s, sizeof(s));
}

void viewSale(sale s,cList cl){
int choice,id,idx;
cout<<"1. View All"<<endl;
    cout<<"2. View by Searching ID"<<endl;
    cin>>choice;
    if (choice==1){
        displayCHASHIER(cl);
    }
else if(choice==2){
    id=getIdCHASHIER();
                    idx=searchByIdCHASHIER(cl,id);
                    if(idx>=0)
                        displayCHASHIER(cl.list[idx]);
}
}


int allocateCHASHIER( cList &cl, int n){
    cl.list=new (nothrow) sale[n];
    if(cl.list==NULL){
        return 0;
    }else{
        cl.c=0;
        cl.cavail=n;
        return 1;
    }

}
int resizeCHASHIER(cList & cl,int n){
   sale * tmp;
    tmp=new (nothrow) sale[cl.c + n];
    if(tmp==NULL) return 0;
    for(int i=0; i<cl.c; i++)
        tmp[i]=cl.list[i];
    delete [] cl.list;
    cl.list=tmp;
    cl.cavail=n;
    return 1;
}
int addCHASHIER(fstream & chashier, cList & cl, sale s){
    if(cl.cavail==0)
        if(!resizeCHASHIER(cl,10)) return 0;
    chashier.seekp(0,ios::end);
    chashier.write((char *)&s, sizeof(s));
    chashier.flush();
    cl.list[cl.c]=s;
    cl.c++;
    cl.cavail--;
    return 1;
}
int openFileCHASHIER(fstream & chashier, char * path){
    chashier.open(path, ios::in | ios::out | ios::binary);
    if(chashier.is_open()){
        return 1;
    }else{
        ofstream ofs(path, ios::out | ios::binary);
        if(ofs){
            ofs.close();
            chashier.open(path, ios::in | ios::out | ios::binary);
            return 1;
        }else{
            return 0;
        }
    }

}
int loadingCHASHIER(fstream & chashier, char * path,cList & cl){
    int n;
    sale s;
    if(openFileCHASHIER(chashier,path)){
        n=fileSizeCHASHIER(chashier)/sizeof(sale);
        if(allocateCHASHIER(cl,n+10)){
            chashier.seekg(0, ios::beg);
            for(int i=0; i<n; i++){
                chashier.read((char *)&s, sizeof(s));
                cl.list[i]=s;
            }
            cl.cavail=10;
            cl.c=n;
            return 1;
        }else{
            return 2;
        }
    }else
        return 0;
}

long fileSizeCHASHIER(fstream & chashier){
    if(chashier){
        chashier.seekg(0, ios::end);
        return chashier.tellg();
    }else
        return -1;
}

void displayCHASHIER(cList cl){
    int n=1;
    for(int i=0; i< cl.c; i++){
        if(cl.list[i].bookId>=0){
            cout << "#" << n<<" c"<<endl;
            displayCHASHIER(cl.list[i]);
            cout <<endl;
            n++;
        }
    }
}

void errorCHASHIER(ERRORCHASHIER errID){
    switch(errID){
        case INSUFFICIENT_MEMORY:
            cout << "The system doesn't have enough memory!"<<endl;
            break;
        case CHASHIER_NOT_FOUND:
            cout << "CHASHIER not found in the database!"<<endl;
            break;
        case CHASHIERFILE_OPEN_FAILED:
            cout << "Unable to open the file!"<<endl;
            break;
        case CHASHIER_NOT_MODIFIED:
            cout << "CHASHIER is not modified!"<<endl;
            break;
    }
}

void removeDeletedCHASHIER(fstream &chashier, char *path){
    sale s;
    ofstream ofs("temp.bin",ios::out|ios::binary);
    int noOfc=fileSize(chashier)/sizeof(s),i=0;
    chashier.seekg(0,ios::beg);
    while(i<noOfc){
        chashier.read((char *)&s, sizeof(s));
        if(s.bookId>=0){
            ofs.write((char *)&s,sizeof(s));
            ofs.flush();
    	}
		i++;
    }
    chashier.close();
    remove(path);
    ofs.close();
    rename("temp.bin",path);
}
