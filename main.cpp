/* countInputChars.cpp
 * 
 * Name: Bhavana Laxmi R
 * Class: CS 141
 * Professor: Mark Hallenbeck
 * program 3
        Count the number of occurrences of each letter from file Macbeth.txt
 */
#include <iostream>
#include <cctype>       // For the letter checking functions
#include <fstream>       // For file input
#include <iomanip>      // For setw
#include <cstdlib> 
#include <string>

using namespace std;

#define LIMIT 26        // Max array size, which is number of alphabet
#define SIZE 8
int size = 8;
int lettersArray[26][9];
string Languages[] = {"MacbethEnglish.txt","MacbethFinnish.txt","MacbethFrench.txt","MacbethGerman.txt","MacbethHungarian.txt",
                         "MacbethItalian.txt","MacbethPortuguese.txt","MacbethSpanish.txt"};
int alphabets[LIMIT][SIZE+1];

void frequencyCount(string Language, int n){
    
    ifstream inputFileStream;  // declare the input file stream
   char c = ' ';              // input character

    
    
   
   inputFileStream.open( Language.c_str());   // Convert C++ string to expected C-style string
   if( !inputFileStream.is_open()) {
        cout << "Could not find input file.  Exiting..." << endl;
        exit( -1);
   }

    for (int i=0; i<LIMIT; i++) {

      lettersArray[i][n] = 0;   //2d array

    }

  
   while( inputFileStream >> c) {
      
       if( isalpha( c)) {
          c = toupper( c);
          lettersArray[c-'A'][n]++;
       }
   }
   
   inputFileStream.close(); //closes the file
}

void displayBoard()
{
     cout << "Reading characters from a file... " << endl;
  cout << "The alphabetic characters are: \n";
    cout<< "Letter Frequency count:\n    Enlg   Finn   Fren   Germ   Hung   Ital   Port   Span\n";   
  for (int i=0; i<LIMIT; i++) {
    cout << (char)(i+'A') << ":"; 
    for(int k = 0 ; k<size; k++){
       if ( lettersArray[i][k] != 0 ) 
       {
     cout << setw(6) << lettersArray[i][k] << " ";
   }

    }
    cout << endl;

}
}

//------------------------------------------------------------------------------------

void swap(int& xp,int& yp){
    int temp = xp;
    xp = yp;
    yp = temp;
}

void bubblesort(int arr[],int onlylettersArray[],int k)
{
    char array1D[LIMIT];
    char array2D[LIMIT][size];
    char letters2dArray[size][LIMIT];
    int offset = 26;
    for (int i=0;i<LIMIT-1;i++){
        for(int j=0;j<LIMIT-1-i;j++){
            if (arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
                swap(onlylettersArray[j], onlylettersArray[j+1]);
            }
            
        }
    }
    for ( int p=0; p<LIMIT; p++)
    {
        array1D[p] = onlylettersArray[p];
    }
    
}
    


void frequencyOrder(int k)
{ 
    int tempArray[LIMIT];
    int onlylettersArray[LIMIT];
    
    for(int n=0;n<LIMIT;n++){
        onlylettersArray[n]= int('A'+ n);
    }
   
     
    for(int p = 0; p<LIMIT; p++){
        tempArray[p]=lettersArray[p][k];
    }
    
    bubblesort(tempArray,onlylettersArray,k);
    for(int l=0;l<LIMIT;l++)
    {
        alphabets[l][k] = onlylettersArray[l];
    }  
}

//----------------------------------------------------------------------------------
  void UserInputFrequencyOrder()
  {
      int userInputFreq[LIMIT];
      string UserInput;
      getline(cin,UserInput);
      
      // Write to file
      ofstream file("input.txt");
      file << UserInput;
      file.close();
      
      for( int pos = 0; pos<size;pos++)
         frequencyCount(Languages[pos],pos);
      frequencyCount("input.txt",8);
      
      for(int i=0;i<LIMIT;i++){
          cout << (char)(i+65) << ":" << lettersArray[i][8] << " ";
      }
      cout <<endl;
      
      for(int t=0;t<size+1;t++){
        frequencyOrder(t);
      }
       
        cout<< "Letter Frequency order:\n\n    Enlg   Finn   Fren   Germ   Hung   Ital   Port   Span    USER\n"; 
         for(int i=0;i<LIMIT;i++){
            for(int j=0;j<size+1;j++)
                cout<<setw(6)<<char(alphabets[i][j]) << " ";
            cout << endl;
         }
   }


//-------------------------------------------------------------------------------

void findLanguage(){ 
    
}

void step1() {
    for( int pos = 0; pos<size;pos++)
         frequencyCount(Languages[pos],pos);
       displayBoard();
}

void step2() {
    
}


//-----------------------------------------------------------------------------------
int main()
    {
int userInput;
   string UserInput;
   cout<<"Program 3: Which Language.\n"
       <<"Select from the following stages of output to display:\n"
       <<"1. Letter frequency counts\n"
       <<"2. Letter frequency order\n"
       <<"3. Get user input and display frequency counts\n"
       <<"4. Get user input, display frequency counts, and display language\n"
       <<"0. Exit the program Your choice\n";
    cin>>userInput;
//     cin.ignore();
    
    
       // Step 1
    if (userInput == 1){
        step1();
    }
    // Step 2
    if (userInput == 2){
        step1();
        step2();
    }
    // Step 3
        if (userInput == 3){
            step1();
            step2();
            cout << endl << "Copy and paste a paragraph of text to be analyzed, followed by ^z (PC) or ^d (Mac):" << endl;
            cin.ignore();
            UserInputFrequencyOrder();
        }
    // Step 4
        if (userInput == 4) {
            step1();
            step2();
            cout << endl << "Copy and paste a paragraph of text to be analyzed, followed by ^z (PC) or ^d (Mac):" << endl;
            cin.ignore();
            UserInputFrequencyOrder();
            
            // Calculating perc for alphabet
            double **lang_percentage = new double*[size];
            
            for (int a=0;a<size;a++) {
                lang_percentage[a] = new double[LIMIT];
                int total = 0;
                
                for (int j=0; j<LIMIT; j++) {
                    total = total + lettersArray[j][a];
                }
                
                for (int j=0; j<LIMIT; j++) {
                    lang_percentage[a][j] = static_cast<double>(lettersArray[j][a])/total;
                }
            }
            
            // Calculating perc for user
            double *user_percentage = new double[size];
            int total = 0;
            
            for (int j=0; j<LIMIT; j++) {
                total = total + lettersArray[j][8];
            }

            for (int j=0; j<LIMIT; j++) {
                user_percentage[j] = static_cast<double>(lettersArray[j][8])/total; // converting to double
            }
            
            // Calculating error and defining language
            double smallestError = 0;
            double error = 0;
            int lang = 0;
            double difference =0 ;
            
            
            for (int a=0;a<size;a++) {
                error = 0;
                for (int j=0; j<LIMIT; j++) {
                    difference = lang_percentage[a][j] - user_percentage[j];  // finding the percentage difference
                    error += difference*difference;
                }
                if (a == 0) 
                    smallestError = error;
                if (error < smallestError) {  // comparing percentages
                    lang = a;
                    smallestError = error;
                }
                
            }
            cout << "Language is "; // to determine the language
            switch(lang+1) {
                case 1:
                    cout << "English" << endl;
                    break;
                case 2:
                    cout << "Finnish" << endl;
                    break;
                case 3:
                    cout << "French" << endl;
                    break;
               case 4:
                    cout << "German" << endl;
                    break;
                case 5:
                    cout << "Hungarian" << endl;
                    break;
               case 6:
                    cout << "Italian" << endl;
                    break;
               case 7:
                    cout << "Portuguese" << endl;
                    break;
               case 8:
                    cout << "Spanish" << endl;
                    break;
           } 
        }
        
    
   return 0;
}//end main()



