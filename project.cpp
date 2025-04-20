#include<bits/stdc++.h>
using namespace std;

const string GREEN_BG = "\033[42m";  // Green background
const string YELLOW_BG = "\033[43m"; // Yellow background
const string RED_BG = "\033[41m";    // Red background
const string RESET = "\033[0m";      // Reset all formatting

string randomwordpicker(){
    vector<string> words;
    ifstream file("validwords.txt");
    if(!file){
        cerr<<"Error: Could not open the file."<< endl;
        return 0;
    }
    string word;
    while(file>>word){
        words.push_back(word);
    }
    if(words.empty()){
        cerr << "No words found in the file!" << endl;
        return 0;
    }
    // Seed random number generator
    srand(time(0));
    // Pick a random index
    int randomIndex = rand()%words.size();
    string randomword=words[randomIndex];
    return randomword;
}

bool validword(string s){
    set<string> validWords;
    ifstream file("validwords.txt");
    bool dict_valid=true;
    if(!file){
       cerr<<"Error: Could not open the file."<<endl;
    }
    string word;
    while(file>>word){
      validWords.insert(word);
    }
    if(validWords.count(s)){
        return true;
    }
    else{
        return false;
    }
}

string genstring(string s,string t){
    map<char,int> h1,h2;
    int len=s.size();
    for(int i=0;i<len;i++){
        h1[s[i]]++;
    }
    for(int j=0;j<len;j++){
        h2[t[j]]++;
    }
   string p(len,' ');
    for(int i=0;i<len;i++){
        if(s[i]==t[i]){
            p[i]='G';
            h1[t[i]]--;
        }
        else{
            p[i]='R';
        }
    }
    for(int i=0;i<len;i++){
        if(p[i]=='R'){
            if(h1[t[i]]>0){
                p[i]='Y';
                h1[t[i]]--;
            }
        }
    }
    return p;
}

string lowerword(string s){
    for(auto &c:s){
           c=tolower(c);
    }
    return s;
}
string upperword(string s){
    for(auto &c:s){
           c=toupper(c);
    }
    return s;
}

void colourstring(string s,string t){
    string temp(5,' ');
    for(int i=0;i<5;i++){
        if(s[i]=='G'){
            cout<<GREEN_BG<<t[i]<<RESET;
        }else if(s[i]=='Y'){
            cout<<YELLOW_BG<<t[i]<<RESET;
        }else{
            cout<<RED_BG<<t[i]<<RESET;
        }
    }
    cout<<RESET;
    cout<<endl;
}

bool alreadymade(string s,set<string> p){
     if(p.find(s)==p.end()){
        return false;
     }
     else{
        return true;
     }
}

void generatepattern(const vector<string> &patterns) {
    for (const auto &p : patterns) {
        for (char c : p) {
            if (c == 'G') cout << "🟩";
            else if (c == 'Y') cout << "🟨";
            else cout << "⬜";
        }
        cout << endl;
    }
}

void printstats(vector<int> stats){
    for(int i=0;i<6;i++){
        cout<<i+1<<"|";
        for(int j=0;j<stats[i];j++){
            cout<<"🟩";
        }
        cout<<stats[i]<<endl;
    }
    cout<<endl;
}

int main(){
    bool play=true;
    vector<int> stats(6,0);
    int wrong_count=0;
    int right_count=0;
    while(play){
        string word=randomwordpicker();
        word=upperword(word);
        int guesscount=0;
        bool won=false;
        cout<<"Welcome to Wordle"<<endl;
        set<string> already;
        vector<string> pattern;
        while(guesscount<6 && !won){
            cout<<"Enter a 5 Letter Word to Guess: ";
            string guess;
            cin>>guess;
            guess=lowerword(guess);
            if(validword(guess) && !alreadymade(guess,already)){
               guesscount++;
               already.insert(guess);
               cout<<"Guess "<<guesscount<<": ";
               guess=upperword(guess);
               pattern.push_back(genstring(word,guess));
               colourstring(genstring(word,guess),guess);
               if(genstring(word,guess)=="GGGGG"){
                  cout<<"Correct guess !! "<<endl;
                  cout<<"Wordle Result: "<<endl;
                  cout<<already.size()<<"/"<<"6"<<endl;
                  generatepattern(pattern);
                  stats[guesscount-1]++;
                  right_count++;
                  won=true;
               }
            }else if(alreadymade(guess,already)){
                cout<<"Guess has already been made !!"<<endl;
            }
            else{
                cout<<"Not a valid word !!"<<endl;
            }
        }
        if(!won){
            cout<<"You ran out of guesses !!"<<endl;
            cout<<"The word was: "<<upperword(word)<<endl;
            cout<<"Wordle Result"<<endl;
            cout<<"x/6"<<endl;
            generatepattern(pattern);
            wrong_count++;
        }
        cout<<"Display User Stats?"<<endl;
        cout<<"(Y for yes,N for no)"<<endl;
        string choice2; cin>>choice2;
        choice2=upperword(choice2);
        if(choice2=="Y"){
            cout<<"USER STATS: "<<endl;
            cout<<"No of Right Guesses: "<<right_count<<endl;
            cout<<"No of Wrong Guesses: "<<wrong_count<<endl;
            printstats(stats);
        }
        cout<<"Play again ?"<<endl;
        cout<<"(Y for yes,N for no)"<<endl;
        string choice; cin>>choice;
        choice=upperword(choice);
        if(choice!="Y"){
            play=false;
            cout<<"Thanks for playing"<<endl;
        }
    }
}
