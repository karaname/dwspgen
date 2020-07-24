PKG_CONFIG=`pkg-config --cflags --libs gtk+-3.0`
OBJECTS=obj/main.o obj/handlers.o
LVLDB=-g3
SRCDIR=src
OBJDIR=obj
BIN_NAME=dwspgen

$(BIN_NAME): $(OBJECTS)
	gcc $(LVLDB) $(PKG_CONFIG) -o $(BIN_NAME) $(OBJECTS)

$(OBJDIR)/main.o: $(SRCDIR)/main.c
	@test -e $(OBJDIR) || mkdir $(OBJDIR)
	gcc $(LVLDB) -c $(SRCDIR)/main.c -o $(OBJDIR)/main.o $(PKG_CONFIG)

$(OBJDIR)/handlers.o: $(SRCDIR)/handlers.c
	gcc $(LVLDB) -c $(SRCDIR)/handlers.c -o $(OBJDIR)/handlers.o $(PKG_CONFIG)

install:
	install $(BIN_NAME) /usr/local/bin/

uninstall:
	rm -rf /usr/local/bin/$(BIN_NAME)

clean:
	rm -rf $(OBJDIR)
