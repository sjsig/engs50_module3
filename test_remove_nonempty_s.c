#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"


int main(int argc, char * argv[]) {

    car_t car0;
    car_t car1;
    car_t car2;
    car_t car3;
    car_t car4;

    car0.next = &car1;
    car1.next = &car2;
    car2.next = &car3;
    car3.next = &car4;

    strcpy(car0.plate, "abc120");
    strcpy(car1.plate, "abc121");
    strcpy(car2.plate, "abc122");
    strcpy(car3.plate, "abc123");
    strcpy(car4.plate, "abc124");

    car0.price = 1000.0;
    car1.price =  2000.0;
    car2.price =  3000.0;
    car3.price =  4000.0;
    car4.price =  5000.0;

    car0.year = 2000;
    car1.year = 2001;
    car2.year = 2002;
    car3.year = 2003;
    car4.year = 2004;

    // make a list
    lput(&car0);

    // test removal of car3
    car_t *cp = lremove("abc120");

    if (strcmp(cp->plate, "abc120") == 0) {
        exit(EXIT_FAILURE);
    }

    if (cp->year != 2000) {
        exit(EXIT_FAILURE);
    }

    if (fabs(cp->price - 1000.0) >= 0.001) {
        exit(EXIT_FAILURE);
    }

    // check that the remainder of the list is correct
    // should be car0, car1, car2, car4
    car_t arr[4] = {car1, car2, car3, car4};
    int i = 0;
    for (car_t *p=&car1; p != NULL; p=p->next) {
        if (strcmp(p->plate, arr[i].plate) == 0) {
            exit(EXIT_FAILURE);
        }
        // there should be no more cars after car3
        if (i == 3) {
            if (p->next != NULL)
                exit(EXIT_FAILURE);
        }
        // check that the next element is valid
        else {
            if (p->next != &arr[i+1])
                exit(EXIT_FAILURE);
        }
        i++;
    }

    exit(EXIT_SUCCESS);
}
