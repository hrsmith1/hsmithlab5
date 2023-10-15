#include <stdio.h>

int scorefinder(int score){
    for(int td2 = 0; td2 <= score/8; td2++){
        for (int tdf = 0; tdf <= score/7; tdf++){
            for (int td=0; td<= score/6; td++){
                for(int fg=0; fg<=score/3; fg++){
                    for(int s=0; s<=score/2; s++){
                        if (td2*8 + tdf*7 + td*6 + fg*3 + s*2 == score){
                            printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdf, td, fg, s);
                        }}}}}}
                        return 0; }
int main(){
    int score = 6;
    printf("Enter 0 or 1 to STOP \n");
    while (score > 1){
        printf("Enter the NFL score:");
        scanf("%d", &score);
        if (score > 1){
            printf("possible combinations of scoring plays:\n");
            scorefinder(score);
        }
    }
    printf("Program Ending\n");
    return 0; 
}