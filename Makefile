

all: app run

app: dungeon.c
	gcc -o app dungeon.c arealib.c

run: app
	./app

clean:
	rm app