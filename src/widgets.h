extern struct Containers {
  GtkWidget *vbox;
  GtkWidget *first_row_grid;
  GtkWidget *second_row_grid;
  GtkWidget *check_grid;
} cont;

extern struct Controllers {
  GtkWidget *pass_entry;
  GtkWidget *digits_check_button;
  GtkWidget *symbols_check_button;
  GtkWidget *len_spin_button;
} cllr;

extern struct Buttons {
  GtkWidget *generate_button;
  GtkWidget *to_clipboard_button;
  GtkWidget *clear_clipboard_button;
} butt;
