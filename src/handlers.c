#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "widgets.h"

static char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void remove_substr(char *substr)
{
  int len_alpha = strlen(alpha);
  int len_sub = strlen(substr);

  for (int i = 0; i < len_alpha; i++) {
    for (int j = 0; j < len_sub; j++) {
      if (alpha[i] == substr[j]) {
        memmove(&alpha[i], &alpha[i + 1], len_alpha - i);
      }
    }
  }
}

void generate(char *s, int len)
{
  int index;
  srand(time(NULL));
  for (index = 0; index < len; index++) {
    s[index] = alpha[rand() % (strlen(alpha))];
  }
  s[index] = '\0';
}

void on_generate_button_clicked(GtkWidget *generate_button)
{
  int value;
  char pass_buffer[50];
  value = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cllr.len_spin_button));
  generate(pass_buffer, value);
  gtk_entry_set_text(GTK_ENTRY(cllr.pass_entry), pass_buffer);
}

void on_clipboard_button_clicked(GtkWidget *to_clipboard_button)
{
  GtkClipboard *clipboard;
  const char *text = gtk_entry_get_text(GTK_ENTRY(cllr.pass_entry));
  clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
  gtk_clipboard_set_text(clipboard, text, -1);
}

void on_clear_clipboard_button_clicked(GtkWidget *clear_clipboard_button)
{
  GtkClipboard *clipboard;
  clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
  gtk_clipboard_clear(GTK_CLIPBOARD(clipboard));
}

void on_digits_check_button_toggled(GtkWidget *digits_check_button)
{
  gboolean digits_status = gtk_toggle_button_get_active(
    GTK_TOGGLE_BUTTON(cllr.digits_check_button));
  (digits_status == 1) ? strcat(alpha, "0123456789") : remove_substr("0123456789");
}

void on_symbols_check_button_toggled(GtkWidget *symbols_check_button)
{
  gboolean symbols_status = gtk_toggle_button_get_active(
    GTK_TOGGLE_BUTTON(cllr.symbols_check_button));
  (symbols_status == 1) ? strcat(alpha, "!#$%&@*^~") : remove_substr("!#$%&@*^~");
}
