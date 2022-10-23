//
// Created by jeanc on 17/10/2022.
//

#include "Menu.h"

Menu::~Menu() {

}

Menu::Menu() {
    theTree = new TwoFour();
}

void Menu::mainMenu() {
    int opcion;

    srand(time(NULL));


    while(true){
        try {
            cout << "----------------------------------------------------" << endl;
            cout << "( 1 ) Insert n random Integers" << endl;
            cout << "( 2 ) Perform 2n operations with probability" << endl;
            cout << "( 3 ) Print In Order" << endl;
            cout << "( 4 ) View Tree level by level" << endl;
            cout << "( 5 ) Insert an element" << endl;
            cout << "( 6 ) Delete an element" << endl;
            cout << "( 7 ) find an element" << endl;
            cout << "( 8 ) Salir" << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Please enter valid input: ";
            cin >> opcion;
            if(cin.fail()){
                cin.clear();
                cin.ignore(1024,'\n');
                cout<<"Only enter numeric data"<<endl;
                Sleep(2000);
                mainMenu();
            }
            if(opcion<1||opcion>8){
                cin.clear();
                cout<<"Only numbers between 1-8"<<endl;
                Sleep(2000);
                mainMenu();
            }
            switch (opcion) {
                case 1: {
                    insertN();
                    break;
                }
                case 2: {
                    probabilityN();
                    break;
                }
                case 3: {
                    printInOrder();
                    break;
                }
                case 4: {
                    viewTreeLevels();
                    break;
                }
                case 5: {
                    insertElement();
                    break;
                }
                case 6: {
                    deleteElement();
                    break;
                }
                case 7: {
                    findElement();
                    break;
                }
                case 8: {
                    cout << "Thank you!!!" << endl;
                    system("pause");
                    exit(0);
                }
            }
        }catch (RuntimeException e){
            cout<<e.getMsg()<<endl;
        }
    }

}

void Menu::insertN() {
    int n=0;
    TwoFour* twoFour=theTree;
    cout << "Enter the value of n" << endl;
    cin >> n;
    for (int a = 1; a < n + 1; a++) {
        Node *present = theTree->find(a);
        if (present != nullptr) {
            //System.out.println("Data Already present!!");
        } else {
            theTree->insert(a);
        }
    }
}

void Menu::probabilityN() {
    int n=0;
    cout << "Enter the value of n" << endl;
    //n = getInt();
    cin >> n;
    int operation = 0;
    int searchCount = 0;
    int insertCount = 0;
    int deleteCount = 0;
    auto startTime = chrono::system_clock::now().time_since_epoch();
    while (operation < (2 * n)) {

        int x1 = rand() % 100;
        int x2 = rand() % 100;
        int x3 = rand() % 100;

        double f1 = (double) rand() / RAND_MAX;
        double rand1 = 0 + f1 * (1 - 0);

        double f2 = (double) rand() / RAND_MAX;
        double rand2 = 0 + f2 * (1 - 0);

        double f3 = (double) rand() / RAND_MAX;
        double rand3 = 0 + f3 * (1 - 0);

        if (rand1 < 0.4) {
            // Making sure insert operation runs at 0.4
            // probability
            //int x = random->nextInt(n);

            Node *present = theTree->find(x1);
            if (present != nullptr) {
                //System.out.println("Data Already present!!");
            } else {
                theTree->insert(x1);
            }
            operation++;
            insertCount++;

        }

        //rand = random.nextDouble();
        if (rand2 < 0.25) { // Making sure delete operation runs at 0.25 //
            // probability
            //int x = random.nextInt(n);

            Node *del = theTree->find(x2);
            if (del != nullptr) {
                if (theTree->deleteNode(del, x2) != nullptr) {//System.out.println("Deleted" + x);
                } else {
                    //System.err.println("Not Deleted!!!");
                }
            } else
                //System.out.println("Could not find " + x);
                operation++;
            deleteCount++;

        }
        //rand = random.nextDouble();
        if (rand3 < 0.35) { // Making sure search operation runs at 0.35 //
            // probability
            theTree->find(/*random.nextInt(n)*/x3);
            operation++;
            searchCount++;

        }
    }
    auto endTime = chrono::system_clock::now().time_since_epoch();

    cout << "Total No. of search operations performed :" << searchCount << endl;
    cout << "Total No. of delete operations performed :" << deleteCount << endl;
    cout << "Total No. of insert operations performed :" << insertCount << endl;
    cout << "Total Time Taken: " << endTime.count() - startTime.count() << " nanoseconds" << endl;
}

void Menu::printInOrder() {
    cout << "In Order: " << endl;
    cout<<theTree->displayTree(1);
}

void Menu::viewTreeLevels() {
    cout << "Tree:" << endl;
    cout<<theTree->displayTree(0);
}

void Menu::insertElement() {
    int value;
    cout << "Enter value to insert: " << endl;
    cin >> value;
    Node *present = theTree->find(value);
    if (present != nullptr) {
        cout << "Data Already present!!" << endl;
    } else {
        theTree->insert(value);
    }
}

void Menu::deleteElement() {
    int value;
    cout << "Enter value to delete: " << endl;

    cin >> value;
    Node *del = theTree->find(value);
    if (del != nullptr) {
        if (theTree->deleteNode(del, value) != nullptr)
            cout << "Deleted" << value << endl;
        else {
            cout << "Not Deleted!!!" << endl;
        }
    } else {
        throw RuntimeException("Could not find");
    }
}

void Menu::findElement() {
    int value;
    cout << "Enter value to find: " << endl;

    cin >> value;
    Node *found = theTree->find(value);
    if (found != nullptr) {
        cout << "Found " << value << endl;
    } else {
        throw RuntimeException("Could not find");
    }
}
