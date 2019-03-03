/*
** EPITECH PROJECT, 2018
** pong
** File description:
** yes
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int check_error(char **yo)
{
    int j = 0;
    int temp = 1;
    
    while (yo[temp] != NULL) {
        j = 0;
        while (yo[temp][j] != '\0') {
            if (yo[temp][j] <= '9' && yo[temp][j] >= '0' || yo[temp][j] == '-' || yo[temp][j] == '.')           
            j++;
            else
                return (84);
        }
        temp++;
    }
    if (temp == 8)
        return (1);
    else
        return (84);
    return (1);
}

float angle_maker(float xv, float yv, float zv)
{
    float adja = 0;
    float hypo = 0;
    float angle = 0;
    float pi = M_PI;

    hypo = pow(xv, 2) + pow(yv, 2) + pow(zv, 2);
    adja = pow(xv, 2) + pow(yv, 2);
    hypo = sqrt(hypo);
    adja = sqrt(adja);
    angle = adja / hypo;
    angle = acosf(angle);
    angle *= 180;
    angle /= pi;

    return (angle);
}

int check_it_touch(float z0, float z1, float angle)
{
    if (z1 == z0) {
        printf("The incidence angle is :\n%.2f degrees", angle);
    }
    else if (z1 > z0 && z0 > 0) {
        printf("The incidence angle is :\n%.2f degrees", angle);
    }
    else if (z0 > z1 && z1 > 0) {
        printf("The incidence angle is :\n%.2f degrees", angle);
    }
    else
        printf("The ball won't reach the bat");
    return (0);
}

int main(int argc, char **argv)
{
    int k = 1;
    int j = 0;
    if (check_error(argv) == 84)
        return (84);
    float x0 = atof(argv[1]);
    float y0 = atof(argv[2]);
    float z0 = atof(argv[3]);
    float x1 = atof(argv[4]);
    float y1 = atof(argv[5]);
    float z1 = atof(argv[6]);
    float n = atof(argv[7]);

    float xv = atof(argv[4]) - atof(argv[1]);
    float yv = atof(argv[5]) - atof(argv[2]);
    float zv = atof(argv[6]) - atof(argv[3]);

    float tnx = n * xv + x1;
    float tny = n * yv + y1;
    float tnz = n * zv + z1;
    float angle = angle_maker(xv ,yv, zv);
    
    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", xv, yv, zv);
    printf("At time t + %.0f, ball coordinates will be:\n", n);
    printf("(%.2f, %.2f, %.2f)\n",tnx, tny, tnz);
    if (angle == 0.00 || angle == 90.00)
        printf("The ball won't reach the bat.");
    else
        check_it_touch(z0, z1, angle);
    return (0);
}
