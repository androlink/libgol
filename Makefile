NAME = libgol.a
ARGS = 
AR = ar -rcs
CC = cc
RMF = rm -f

CFLAGS = -g
DFLAGS = -MP -MMD

SDIR = srcs
BDIR = .build
DDIR = $(BDIR)
HDIR = includes

LIB_PATH :=
LIB_DIR :=
LIB_INCLUDE :=
LIB_FLAGS :=

SRCS :=
SRCS += gol_init.c
SRCS += gol_get_at.c
SRCS += gol_set_at.c
SRCS += gol_update.c
SRCS += util_bzero.c
SRCS += gol_expend.c
SRCS += gol_print.c

SFILES = $(SRCS:%=$(SDIR)/%)

DFILES = $(SRCS:%.c=$(DDIR)/%.d)

OFILES = $(SRCS:%.c=$(BDIR)/%.o)

LIB_FLAGS := 

all:
	@echo "compiling $(NAME):"
	@$(MAKE) $(NAME)

bonus:	all

$(NAME) : $(OFILES) | $(LIB_PATH)
	$(AR) -o $@ $(OFILES)
	@echo "$(NAME) compilation done";

-include $(DFILES)

$(BDIR)/%.o : $(SDIR)/%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(HDIR) $(LIB_INCLUDE)
	@echo "	$@"

clean	::
	@echo "cleaning $(NAME)";
	@$(RMF) $(OFILES) $(DFILES)

re		::	fclean
	@$(MAKE) all

fclean	::	clean
	@$(RMF) $(NAME)

force :

.PHONY: clean re fclean force al
