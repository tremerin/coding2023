#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Score points by scanning valuable fish faster than your opponent.
 **/

typedef struct s_dron
{
    int drone_id;
    int drone_x;
    int drone_y;
    int emergency;
    int battery;
    int mX;
    int mY;
    int light;
    int path_point;
}   t_dron;

typedef struct s_fish
{
    int creature_id;
    int color;
    int type;
}   t_fish;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

int main()
{
    t_dron dron[2];
    dron[0].path_point = 0;
    dron[1].path_point = 15;
    t_point path[16];
    path[0].x  = 2000; path[0].y  = 2000;
    path[1].x  = 2000; path[1].y  = 4000;
    path[2].x  = 2000; path[2].y  = 6000;
    path[3].x  = 2000; path[3].y  = 8000;
    path[4].x  = 4000; path[4].y  = 8000;
    path[5].x  = 6000; path[5].y  = 8000;
    path[6].x  = 8000; path[6].y  = 8000;
    path[7].x  = 8000; path[7].y  = 6000;
    path[8].x  = 6000; path[8].y  = 6000;
    path[9].x  = 4000; path[9].y  = 6000;
    path[10].x = 4000; path[10].y = 0;
    path[11].x = 6000; path[11].y = 4000;
    path[12].x = 8000; path[12].y = 4000;
    path[13].x = 8000; path[13].y = 2000;
    path[14].x = 6000; path[14].y = 2000;
    path[15].x = 4000; path[15].y = 2000;
    
    int creature_count;
    t_fish *n_fish = malloc(sizeof(t_fish) * creature_count);
    scanf("%d", &creature_count);
    for (int i = 0; i < creature_count; i++) {

        scanf("%d%d%d", &n_fish[i].creature_id, &n_fish[i].color, &n_fish[i].type);
    }

    // game loop
    while (1) {
        int my_score;
        scanf("%d", &my_score);
        //fprintf(stderr, "my score: %d\n", my_score);
        int foe_score;
        scanf("%d", &foe_score);
        int my_scan_count;
        scanf("%d", &my_scan_count);
        for (int i = 0; i < my_scan_count; i++) {
            int creature_id;
            scanf("%d", &creature_id);
            fprintf(stderr, "creature id: %d\n", creature_id);
        }
        int foe_scan_count;
        scanf("%d", &foe_scan_count);
        for (int i = 0; i < foe_scan_count; i++) {
            int creature_id;
            scanf("%d", &creature_id);
        }
        int my_drone_count;
        scanf("%d", &my_drone_count);
        for (int i = 0; i < my_drone_count; i++) {
            scanf("%d%d%d%d%d", &dron[i].drone_id, &dron[i].drone_x, &dron[i].drone_y, &dron[i].emergency, &dron[i].battery);
            dron[i].mX = path[dron[i].path_point].x;
            dron[i].mY = path[dron[i].path_point].y;
        }
        int foe_drone_count;
        scanf("%d", &foe_drone_count);
        for (int i = 0; i < foe_drone_count; i++) {
            int drone_id;
            int drone_x;
            int drone_y;
            int emergency;
            int battery;
            scanf("%d%d%d%d%d", &drone_id, &drone_x, &drone_y, &emergency, &battery);
        }
        int drone_scan_count;
        scanf("%d", &drone_scan_count);
        for (int i = 0; i < drone_scan_count; i++) {
            int drone_id;
            int creature_id;
            scanf("%d%d", &drone_id, &creature_id);
        }
        int visible_creature_count;
        scanf("%d", &visible_creature_count);
        for (int i = 0; i < visible_creature_count; i++) {
            int creature_id;
            int creature_x;
            int creature_y;
            int creature_vx;
            int creature_vy;
            scanf("%d%d%d%d%d", &creature_id, &creature_x, &creature_y, &creature_vx, &creature_vy);
        }
        int radar_blip_count;
        scanf("%d", &radar_blip_count);
        for (int i = 0; i < radar_blip_count; i++) {
            int drone_id;
            int creature_id;
            char radar[3];
            scanf("%d%d%s", &drone_id, &creature_id, radar);
        }
        for (int i = 0; i < my_drone_count; i++) {

            // Write an action using printf(). DON'T FORGET THE TRAILING \n
            // To debug: fprintf(stderr, "Debug messages...\n");

            //printf("WAIT 1\n"); // MOVE <x> <y> <light (1|0)> | WAIT <light (1|0)>
            fprintf(stderr, "battery %d: %d\n", i, dron[i].battery);
            if (i == 0)
            {
                if (dron[i].drone_x == path[dron[i].path_point].x && dron[i].drone_y == path[dron[i].path_point].y && dron[i].path_point < 16)
                {
                    dron[i].mX = path[dron[i].path_point].x;
                    dron[i].light = 1;
                    printf("WAIT %d\n", dron[i].light);
                    dron[i].path_point++;
                    dron[i].mX = path[dron[i].path_point].x;
                    dron[i].mY = path[dron[i].path_point].y;
                    
                }
                else if ( dron[i].path_point >= 16)
                {
                    dron[i].mY = 0;
                    dron[i].light = 0;
                    printf("MOVE %d %d %d\n", dron[i].mX, dron[i].mY, dron[i].light);
                }
                else
                {
                    dron[i].light = 0;
                    printf("MOVE %d %d %d\n", dron[i].mX, dron[i].mY, dron[i].light);
                }
            }
            else if (i == 1)
            {
                if (dron[i].drone_x == path[dron[i].path_point].x && dron[i].drone_y == path[dron[i].path_point].y)
                {
                    dron[i].light = 1;
                    printf("WAIT %d\n", dron[i].light);
                    dron[i].path_point--;
                    dron[i].mX = path[dron[i].path_point].x;
                    dron[i].mY = path[dron[i].path_point].y;    
                }
                else
                {
                    dron[i].light = 0;
                    printf("MOVE %d %d %d\n", dron[i].mX, dron[i].mY, dron[i].light);
                }
            }
        }
    }

    return 0;
}