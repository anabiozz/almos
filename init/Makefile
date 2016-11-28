INIT_DIR=$(shell pwd)

SOURCES_INIT=$(shell find $(INIT_DIR) -name '*.c')
OBJECTS_INIT=$(patsubst $(INIT_DIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES_INIT))

OBJ +=

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<