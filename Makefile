

all: app run clean

app: dungeon.c
	gcc -o app dungeon.c arealib.c health.c getchar.c

run: app
	./app

clean:
	rm app