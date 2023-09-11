#ifndef _FUSION_H_
#define _FUSION_H_


#include <stdlib.h>
#include <stdio.h>
#include "type.h"


int fusion(char dem, int tab[][4]);
void slide(char dem, int tab[][4]);
int fusposfindejeu(int tab[][4]);
int deplacementpossible(char dem,int tab[][4]);



#endif /* _FUSION_H_ */
