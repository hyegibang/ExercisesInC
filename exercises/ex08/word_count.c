#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

void print_helper(gpointer key, gpointer value, gpointer data) {
  printf(data, key, GPOINTER_TO_INT(value));
}

int main(int argc, char** argv) {
  // Reads the content from 'PPAP.txt'
  GHashTable* table = g_hash_table_new(g_str_hash,g_str_equal);
  FILE* file = fopen("PPAP.txt","r");
  char buff[128];

  // Count word frequency until the end of the file
  while(fscanf(file,"%s",buff) != EOF) {
    char* key = strdup(buff);

    // If the word already exists in the table, increment the counter by 1
    if (g_hash_table_contains(table,key)) {
      int count = GPOINTER_TO_INT(g_hash_table_lookup(table,key));
      g_hash_table_replace(table,key,GINT_TO_POINTER(count+1));
    }

    // Else add into the table and set counter to 1
    else {
      g_hash_table_insert(table,key,GINT_TO_POINTER(1));
    }
  }

  g_hash_table_foreach(table,(GHFunc) print_helper, "%s: %d \n");
}
