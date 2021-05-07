int different = 0;
for(int j=0; i<team_index; i++){
    for(int k=0; k<players_per_team; k++){
        if(local[i].name != all_teams[j][k].name){
            different = 1;
        }
    }
    if(different == 0){
        goto label;
    }
    different = 0;
}
