// #include "player_data.h"
#include "header.h"
using std::string;


#define PLAYER_CONDITION ((bat_count >=1 && bat_count <=6) && (bowl_count>=2 && bowl_count<=6) && (all_count>=1 && all_count<=6))

//Structure that contains details of a player
struct data_team{
    float value;
    string name = "";
    char team_name;
    string position = "";

    data_team(float temp_value, string temp_name, char init_team, string temp_pos){
        value = temp_value;
        name = temp_name;
        team_name = init_team;
        position = temp_pos;
    }
};
vector<struct data_team> p_data;                            //p_data stands for player_data;
vector<vector<struct data_team>> all_teams;                 //contains all formed teams (after all conditions)

//Global Variables
int count_team1, count_team2;                               //Player count for respective teams
int teams_formed = 1;                                       //to keep track of number of teams
int team_index = -1;                                       
int bat_count = 0, bowl_count = 0, all_count = 0;           //to keep track of number of batsmen, bowlers and all-rounders in a team
int players_per_team = 11;

//Function Declarations
void player_init();
void unique_combination(int l, float sum, float target_sum, vector<struct data_team>& local, vector<struct data_team>& A, int element_count);
void Combination(vector<struct data_team> A, float target_sum);
void show_teams();
//Increase/Decrease position count
void increase_pos(struct data_team &player){
    if (player.position == "BAT")       bat_count++;
    else if (player.position == "BOWL") bowl_count++;
    else if (player.position == "ALL")  all_count++;
}
void decrease_pos(struct data_team &player){
    if (player.position == "BAT")       bat_count--;
    else if (player.position == "BOWL") bowl_count--;
    else if (player.position == "ALL")  all_count--;
}


void player_init(){
    char init_team1, init_team2;
    string temp_pos, temp_name;
    float temp_value;
    //TEAM 1
    cout<<"<---- TEAM 1 ---->\n";
    cout<<"Enter Initial: \n ";
    cin>>init_team1;
    cout<<"Enter player count: \n";
    cin>>count_team1;
    cout<<"\nENTER PLAYER DATA OF TEAM 1 **IN ASCENDING ORDER OF VALUE**\n";
    for(int i=0; i<count_team1; i++){
        cout<<"Enter player name: \n ";
        cin>>temp_name;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Enter " << temp_name << "'s position(BAT/BOWL/ALL): \n ";
        cin>>temp_pos;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if( !((temp_pos == "BAT") || (temp_pos == "BOWL") || (temp_pos == "ALL")) ){
            cout<<"INVALID POSITIONS! ENTER AGAIN\n";
            
            cin>>temp_pos;
        }
        cout<<"Enter " << temp_name << "'s value: \n";
        cin>>temp_value;
        p_data.push_back({temp_value, temp_name, init_team1, temp_pos});
    }
    
    // TEAM 2
    cout<<"<---- TEAM 2 ---->";
    cout<<"\nEnter Initial of Team 2: ";
    cin>>init_team2;
    cout<<"Enter player count: ";
    cin>>count_team2;
    cout<<"\nENTER PLAYER DATA OF TEAM 2  **IN ASCENDING ORDER OF VALUE**\n";
    for(int i=0; i<count_team2; i++){
        cout<<"Enter player name: \n";
        cin>>temp_name;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Enter " << temp_name << "'s position (BAT/BOWL/ALL): \n";
        cin>>temp_pos;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if( !((temp_pos == "BAT") || (temp_pos == "BOWL") || (temp_pos == "ALL")) ){
            cout<<"INVALID POSITION! ENTER AGAIN -->\n ";
            
            cin>>temp_pos;
        }
        cout<<"Enter " << temp_name << "'s value: \n";
        cin>>temp_value;
        p_data.push_back({temp_value, temp_name, init_team2, temp_pos});
    }
}

void unique_combination(int l, float sum, float target_sum, vector<struct data_team>& local, vector<struct data_team>& A, int element_count){
    // If a unique combination is found
    //condition for max teams
    /*
    if (teams_formed > 50){
        goto label;
        cout<<"MORE THAN 50 TEAMS CAN BE FORMED!!!!!\nEdit teams_formed condition to change max number of teams to be shown\n";
    }
    */
    for (int i = 0; i < element_count; i++){
        if ((sum == target_sum) && (element_count == players_per_team)) {
            
            // if(team_index >=500) return;
            for(int i=0; i<players_per_team; i++){
                increase_pos(local[i]);
            }
            // if(((bat_count >=1 && bat_count <=6) && (bowl_count>=2 && bowl_count<=6) && (all_count>=1 && all_count<=6))){
            int different = 1;
            for(int j=0; i<(team_index); i++){
                int flag = 0;
                for(int k=0; k<players_per_team; k++){
                        
                    if(local[k].name != all_teams[j][k].name){
                        flag = 1;
                    }
                }
                if(flag == 0){
                    different = 0;
                }
            }         
            if((different == 1) || (team_index == 0)){
                all_teams.push_back(local);
                // cout<<"Team with "<<bat_count<<" batmen, "<<bowl_count<<" bowlers and "<<all_count<<" all-rounders added\n";             //DEBUG PRINT
                
                team_index++;
                //SHOW TEAMS IF THE CONDITION IS TRUE
                /*
                if(((bat_count >=4 && bat_count <=6) && (bowl_count>=3 && bowl_count<=6) && (all_count>=3 && all_count<=6))){
                    // ++team_index;
                    cout<<"Batsmen = "<<bat_count<<" Bowlers = "<<bowl_count<<" All Rounders = "<<all_count<<endl;;
                    cout<<"{ ";
                    for (int j = 0; j < players_per_team; j++){   
                        if (j != 0)
                        cout << " ";
                        cout << all_teams[team_index][j].name<<"["<<all_teams[team_index][j].team_name<<"]";
                        if (j != players_per_team - 1)
                            cout << ", ";
                    }
                    cout << "}"<< endl;
                }
                */
            }
            ++teams_formed;
            bat_count = 0;          //Reset counts for next team
            bowl_count = 0;
            all_count = 0;
        }
    }
    label:
    // For all other combinations
    for (int i = l; i < A.size(); i++)
    {
        // Check if the sum exceeds target_sum
        if (sum + A[i].value > target_sum)
            continue;
        // Take the element into the combination
        local.push_back(A[i]);
                   
        // Recursive call
        ++element_count;
        unique_combination(i + 1, sum + A[i].value, target_sum, local, A, element_count);
 
        // Remove element from the combination
        local.pop_back();
        --element_count;
    }
}
// Function to sort A and call unique_combination
void Combination(vector<struct data_team> A, float target_sum)
{
    // To store combination
    vector<struct data_team> local;
 
    unique_combination(0, 0, target_sum, local, A, 0);
}

void show_teams(){
    bat_count = 0;          //Reset counts for this function as it also calculates positions
    bowl_count = 0;
    all_count = 0;
    for(int i=0; i < team_index; i++){
        for(int j=0; j < players_per_team; j++){
            increase_pos(all_teams[i][j]);
            
        }
        if(!((bat_count >=4 && bat_count <=6) && (bowl_count>=3 && bowl_count<=6) && (all_count>=3 && all_count<=6))){
            bat_count = 0;          //Reset counts for next team
            bowl_count = 0;
            all_count = 0;
            continue;
        }
        cout << "==> {\t";
        for (int j = 0; j < players_per_team; j++){   
            if (j != 0)
            cout << " ";
            cout << all_teams[i][j].name<<"["<<all_teams[i][j].team_name<<"]";
            if (j != players_per_team - 1)
                cout << ", ";
        }
        cout << "\t}"<< endl;

        float max = 0, second_max = 0;
        int max_index, second_index;
        //Find largest and second largest elements
        for(int j=0; j < players_per_team; j++){
            if(all_teams[i][j].value > max){
                second_max = max;
                max = all_teams[i][j].value;
            }
            else if(all_teams[i][j].value > second_max){
                second_max = all_teams[i][j].value;
            }
        }
        //Find indices of those elements
        for(int j=0; j < players_per_team; j++){
            if(all_teams[i][j].value == max){
                max_index = j;
            }
            else if(all_teams[i][j].value == second_max){
                second_index = j;
            }
        }
        
        cout<<"Captain: "<<all_teams[i][max_index].name<<"\tVice Captain: "<<all_teams[i][second_index].name;
        cout<<"\nBatsmen = "<<bat_count<<" Bowlers = "<<bowl_count<<" All-rounders = "<<all_count;
        cout<<"\n\n";
        // teams_formed++;
        bat_count = 0;          //Reset counts for next team
        bowl_count = 0;
        all_count = 0;
    }
}   

//Backup show_teams() if I mess things up
/*
void show_teams(vector <struct data_team> &local){
    cout << "==> {\t";
    for (int i = 0; i < players_per_team; i++){   
        if (i != 0)
        cout << " ";
        cout << local[i].name<<"["<<local[i].team_name<<"]";
        if (i != players_per_team - 1)
            cout << ", ";
    }
    cout << "\t}"<< endl;

    int max = 0, second_max = 0, max_index, second_index;
        //Find largest and second largest elements
    for(int i=0; i < players_per_team; i++){
        if(local[i].value > max){
            second_max = max;
            max = local[i].value;
        }
        else if(local[i].value > second_max){
            second_max = local[i].value;
        }
    }
        //Find indices of those elements
    for(int i=0; i < players_per_team; i++){
        if(local[i].value == max){
            max_index = i;
        }
        else if(local[i].value == second_max){
            second_index = i;
        }
    }
        

    cout<<"Captain: "<<local[max_index].name<<"\tVice Captain: "<<local[second_index].name;
    cout<<"\nBatsmen = "<<bat_count<<" Bowlers = "<<bowl_count<<" All-rounders = "<<all_count;
    cout<<"\n\n";
    teams_formed++;
        
    return;
}
*/
