CC=gcc
OPTIONS = -W -Wall -std=c89 -pedantic -O3
MLV_COMP =  `pkg-config --cflags MLV`
MLV_LIEN = `pkg-config --libs-only-other --libs-only-L MLV`
MLV_LIB_LIEN =  `pkg-config --libs-only-l MLV`


main: initialisation.o fusion.o joueur.o main.o mlv.o
	$(CC) $(OPTIONS) $(MLV_COMP) $(MLV_LIEN)  initialisation.o fusion.o joueur.o main.o mlv.o -o  main $(MLV_LIB_LIEN)

main.o: main.c main.h
	$(CC) $(OPTIONS) $(MLV_COMP) $(MLV_LIEN) -c main.c $(MLV_LIB_LIEN)

joueur.o: joueur.c joueur.h
	$(CC) $(OPTIONS) -c joueur.c

fusion.o: fusion.c fusion.h
	$(CC) $(OPTIONS) -c fusion.c

initialisation.o: initialisation.c initialisation.h
	$(CC) $(OPTIONS) -c initialisation.c

mlv.o: mlv.c mlv.h
	$(CC) $(OPTIONS) $(MLV_COMP) $(MLV_LIEN) -c mlv.c $(MLV_LIB_LIEN)
clear:
	rm -fr *.o
