// #include "header.h"
#include "functions.h"

int main(){
    player_init();
    cout<<"\n<---- POSSIBLE TEAMS ARE ---->\n\n";
    Combination(p_data, 100);
    show_teams();
    
    cout<<"teams formed: "<<team_index;
}