#include <iostream>
#include <cstdlib>
using namespace std;

namespace gameOptions{
    string animals[] = { "pig" , "sheep" , "cow" , "calf" , "goat" , "hen" , "cock"};
    string countries[] = {"rwanda" , "korea" , "america" , "brazil" , "india" , "canada" , "peru"};
    string boynames[] = {"charles" , "bruno" , "isreal" , "tresor" , "derrick" , "bellamy" , "yves"};
    string girlname[] = {"cynthia" , "gloria" , "divine" , "dorcus" , "arianne" , "mia" , "melissa"};

    string options[] = {"Animals" , "Countries" , "Boy Names" , "Girl Names"};
}

namespace gameDisplay{

    void startWords(int length , string array[]){
        cout<<"Welcome to the guessing game"<<endl;
        cout<<"This is the list of types of words that you can choose from"<<endl;
        for (int i = 0; i < length-1; ++i) {
            cout<<i+1<<" "<<array[i]<<endl;
        }
        cout<<"Enter the number you want to try: ";
    }

    int lengthDeterminor(string array[]){
        int length =  sizeof(array) / sizeof(char);
        return length;
    }

    int printWords(string array[] ){
        int length = lengthDeterminor(array);
        for (int i = 0; i < length-1; ++i) {
            cout<<i+1<<" "<<array[i]<<endl;
        }
    }
}

namespace gameChoices {

    string chooseWord(int number){
        string option;
        switch (number) {
            case 1:
                option = "Animals";
                break;

            case 2:
                option = "Countries";
                break;

            case 3:
                option = "Boys Names";
                break;
            case 4:
                option = "Girls Names";
                break;

            default:
                option = "invalid";
        }
        return option;
    }

    int randomNumber(int limit){
      int randoNumber = 0 + (rand() % 6);
      cout<<randoNumber;
    }
}

string choosingCategory(){
    string optionChoosen = "";
    for (int i = 0; i < 10; --i) {
        gameDisplay::startWords(5 , gameOptions::options);
        int numberChoosen;
        cin>>numberChoosen;
         optionChoosen = gameChoices::chooseWord(numberChoosen);
        if(optionChoosen == "invalid"){
            cout<<"Please choose a valid option in the given list";
        }else{
            break;
        }
    }
    return optionChoosen;
}

int main(){
    string category = choosingCategory();
    cout<<"You have choosen the category of : " <<category;
    gameChoices::randomNumber(6);
    return 0;
}