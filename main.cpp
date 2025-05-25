#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include <fstream> 

using namespace std;

// Prints a divider line for better output readability
void printDivider() {
    cout <<  "\n---------------------------------------\n";
}

// Handles the Sleep activity: wake up or sleep in, updates happiness and time accordingly
void Sleep(int choice,int* happiness, int* time){
    printDivider();
    cout << "Would you like to wake up or sleep in? (1 = Wake up, 2 = Sleep in) : "; 
    cin >> choice;

    if(choice==1){
        cout << "*You woke up*\n";
        cout << "\"What a good morning. The birds are singing so beautifully.\"\n"; 
        *time+=1;
        *happiness= *happiness;
        cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    } 
    else if  (choice==2){
        cout << "*You slept in*\n";
        cout << "\"I finally made up for the sleep i lacked.\" \n";
        *happiness= *happiness+10;
        *time=*time+3;
        cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n ";
    }
    else{
        cout << "You have entered the wrong choice. You are now exiting the game...";
        exit(0);
    }
}

// Handles the Breakfast activity: eat or skip breakfast with some random meal options
void Breakfast(int choice, int* happiness, int* time){
    printDivider();
    cout << "Would you like to eat breakfast or skip it? (1 = Eat, 2 = Skip) : ";
    cin >> choice;
    if (choice==2){
        cout << "*You skipped breakfast*\n";
        cout << "\"I'm not in the mood for breakfast.\"\n";
        *time+=1;
        cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    }
    else if (choice==1)
    {
        if (rand() % 3 == 0)
        { 
            cout << "*You ate out today!*\n";
            *happiness= *happiness+20; 
            *time=*time+2;
            cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
        }
        else { 
            string options[7] = {
                "French Toast",
                "Scrambled eggs",
                "Cereal",
                "Halwa Puri",
                "Pancakes",
                "Avocado Toast",
                "PB&J Sandwich"
            };

            int choice = rand() % 7;
            cout << "*You ate " << options[choice] <<"!*" << endl;
            *happiness= *happiness+10;
            *time=*time+2 ;    
            cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";     
        }
    }
    else{
        cout << "You have entered the wrong choice. You are now exiting the game...";
        exit(0);
    }
    
}

// Handles the Study activity: choose to study or skip, adjusts happiness and time accordingly
void Study(int choice, int* happiness, int* time){
    printDivider();
    cout << "Would you like to study or skip it? (1 = Study, 2 = Skip) : ";
    cin >> choice;
    if(choice==1){
        cout << "Good Job! You studied for all your upcoming tests.\n";
        *happiness= *happiness +10;
        *time=*time +2;
        cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    }
    else if(choice==2){
        cout << "You've got this! One step at a time.\n" ;
        *happiness= *happiness;
        *time= *time + 1;
        cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    }
    else{
        cout << "You have entered the wrong choice. You are now exiting the game...";
        exit(0);
    }

}

// Handles miscellaneous time-passing activities depending on current time, affects happiness and time
void TIME( int* happiness, int* time){
     
    if(*time< 12 && *time> 10){
     printDivider();   
     string options[2] = {
                "*You passed some time by doomscrolling!* ",
                "*You played some games!*  " }; 

                 int choice = rand() % 2;
            cout << options[choice] << endl;
        *happiness+=20;
        *time+=2;
        cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    }
    else if( *time<=10 ){
        printDivider();
        string options[2] = {
                "*You watched a tv show! *",
                "*You listened to music and danced!* " };

             int choice = rand() % 2;
            cout << options[choice] << endl;
            *happiness+=20;
        *time+=3;
        cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    }

}

// Handles Lunch activity: eat or skip with some random meal options
void Lunch(int choice, int* happiness, int* time) {
    printDivider();
    cout << "Would you like to eat lunch or skip? (1 = Eat, 2 = Skip) : ";
    cin >> choice;
    if(choice==1){

        if (rand() % 3 == 0)
        { 
            cout << "*You ate out today!*\n";
            *happiness= *happiness+20; 
            *time=*time+2;
            cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
        }
        else { 
            string options[5] = {
                "Alfredo Pasta",
                "Sandwiches",
                "Salad",
                "Biryani",
                "Ramen" 
            };

            int choice = rand() % 5;
            cout << "*You ate " << options[choice] << "!*\n" << endl;
            *happiness= *happiness+10;
            *time=*time+2 ;    
            cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";      
        }
    }
    else if(choice==2){
        cout << "\"I don't feel like eating lunch today\"" << endl;
       cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    }
    else{
        cout << "You have entered the wrong choice. You are now exiting the game...";
        exit(0);
    }
}

// Handles the Outside activity: choose to go out or stay in with randomized options, updates happiness and time
void Outside(int choice, int* happiness, int* time) {
    printDivider();
    cout << "Would you like to go outside or stay in? (1 = Go, 2 = Stay in) : ";
    cin >> choice;
    if(choice==1){
        
            string options[3] = {
                "a park",
                "watch a movie",
                "hang out with friends" };
                  
            int choice = rand() % 3;
            cout << "Such good weather out! " << endl;
            cout << "*You went to " << options[choice] <<"!* "<< endl;
            *happiness= *happiness+30;
            *time=*time+3 ;   
            cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
           }    

    else if(choice==2){
        cout << "You stayed in today!"; 
        string options[3] = {
                "*It started raining*",
                "\"What a sunny day!\"" ,
                "\"Nice weather out!\""  };
                int choice = rand() % 3;
            cout <<"( " <<options[choice] <<  " ) "<< endl;

            string choices[3] = {
                "*You watched a movie in bed!* ",
                "*You played video games!* ",
                "*You took a nap!* " };
                int choice1 = rand() % 3;
            cout << choices[choice1] << endl;

            *happiness= *happiness+30;
            *time=*time+3 ; 
            cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
             } 
             else{
                cout << "You have entered the wrong choice. You are now exiting the game...";
        exit(0);
    }
    } 

// Handles fun activities with fixed options and updates happiness and time
void FunActivity(int choice, int* happiness, int* time){
    printDivider();
    cout << "\"I wanna do something fun.\" " << endl;
    cout << "Select a number to do a fun activity\n";
    cout << "1) DIY a keychain\n 2)Learn a dance choreo\n 3)Learn Crochet/Knitting\n 4)Draw something cute : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\n*You made a cute badge for your bag ≽^- ˕ -^≼*\n"; 
        break;
    case 2:
        cout << "\n*You learned the dance to your favorite song*\n";
        break;
    case 3:
        cout << "\n*You learned to crochet. It makes your fingers hurt, but it's fun*\n";
        break;
    case 4:
        cout << "\n*You drew a cat ^-^*\n";
        break;
    default:
    cout << "You have entered the wrong choice. You are now exiting the game...";
        exit(0); ; 
        break;
    }
    *happiness=50;
    *time=*time+3;
    cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
}    

// Handles Dinner activity: eat or skip dinner with random meal options
void Dinner(int choice, int* happiness, int* time){
    printDivider();
    cout << "Would you like to eat dinner or skip? (1 = Eat, 2 = Skip) : ";
    cin >> choice;
    if(choice==1){
        *happiness+=50; 
        *time+=2;
        string options[3] = {
                "Pasta",
                "Sushi",
                "Lasagna" 
            };

            int choice = rand() % 3;
            cout << "*You ate " << options[choice] << "!*\n" <<endl;
            cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    }
    else if(choice==2){
        cout << "\"I don't feel like eating dinner\"\n"; 
        *time+=1;
        cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    }
    else{
        cout << "You have entered the wrong choice. You are now exiting the game...";
        exit(0);
    }
}

// Handles short scrolling activity, only allowed if time is before 8 PM
void Scroll(int* happiness, int* time ){
   
    if (*time <20){
        printDivider();
        *time+=1;
        cout << "*You scrolled for a bit*\n"; 
        cout << "(Happiness: " << *happiness << ", " << "Time: "<<  *time << ":00)\n";
    }
}

// Handles end of day summary and prints final stats for the day
void Night(int* happiness, int* time, string playerName,string days ){
    printDivider();
    cout << "\"I'm so sleepy...Goodnight.\"\n";  
    cout << "────୨ৎ──── End of Day Summary ────୨ৎ────\n";  
    cout << "Day: " << days  <<endl; 
    cout << "Final Happiness: " << *happiness << "\n";
    cout << "Final Time: " << *time << ":00\n";
    printDivider();
 
}

// Creates the save file with current game data (overwrites previous file)
void createGameData(string playerName, int happiness, int time, string days) {
    fstream file("saved.txt", ios::out);
    file << "Day: " << days << endl;
    file << "Player: " << playerName << endl;
    file << "Happiness: " << happiness << endl;
    file << "Time: " << time << ":00" << endl;
    file << "------------------------------" << endl;
    file.close();
    cout << "Game data saved.\n";
}

// Appends the current game data to the save file (used for multiple days)
void updateGameData(string playerName, int happiness, int time, string days) {
    fstream file("saved.txt", ios::app);  // append instead of overwrite
    file << "Day: " << days << endl;
    file << "Player: " << playerName << endl;
    file << "Happiness: " << happiness << endl;
    file << "Time: " << time << ":00" << endl;
    file << "------------------------------" << endl;
    file.close();
    cout << "Game data updated for " << days << ".\n";
}

// Deletes the saved data file if it exists
void deleteGameData() {
    if (remove("saved.txt") == 0)
        cout << "Saved game deleted.\n";
    else
        cout << "No saved game to delete.\n";
}


int main(){
    string playerName;
    cout << "Enter your name: ";
    getline(cin, playerName);  

    char yes;
    cout << "would you like to delete saved data?(Enter y/n): " ;
    cin >> yes;
    if(yes=='y'){
        deleteGameData();
    } 
    else if(yes=='n'){
        cout << "The game is starting\n";
    }
    else{
        cout << "Please enter correct letter. Exiting code...";
        exit(0);
    }  

    srand(time(0)); // Seed for randomness
    
    // Array storing days to simulate multiple days of gameplay
    string days[2]= {"Saturday", "Sunday"};

    cout << "═══════ Welcome to One Sweet Weekend ═══════\n"; 

    // Main loop iterating through each day
    for(int i=0;i<2;i++){ 
        cout << "\n\n═════════════════════════════════════════════\n";
        cout << " STARTING A NEW DAY: " << days[i] << " \n";
        cout << "═════════════════════════════════════════════\n";

        int choice;              // stores player choices
        int happiness= 0;       // resets happiness for each day
        int time = 6;           // starting time at 6 AM
        cout << "Starting your day...\n";
        cout << "(Day: " <<days[i] <<", Happiness: " << happiness << ", " << "Time: "<<  time << ":00) " << endl;
        cout << "---------------------------------------\n";
         
        Sleep(choice, &happiness,&time);
        Breakfast(choice, &happiness, &time);
        Study(choice, &happiness, &time);
        TIME(  &happiness, &time);
        Lunch(choice, &happiness, &time);
        Outside( choice, &happiness, &time);
        FunActivity(choice, &happiness, &time);
        Dinner(choice, &happiness, &time);
        Scroll(&happiness,&time);
        Night(&happiness, &time, playerName, days[i] );    

        // Save or update game progress depending on day
        if (i == 0)
            createGameData(playerName, happiness, time, days[i]);
        else
            updateGameData(playerName, happiness, time, days[i]);

        cout << "\n END OF " << days[i] << " \n";
        cout << "═════════════════════════════════════════════\n\n";
    }
} 
