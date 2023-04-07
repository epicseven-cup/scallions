#include <gtk/gtk.h>

// compiles
// gcc $(pkg-config --cflags gtk4) -o name-gtk name-gtk.c $(pkg-config --libs gtk4)

static void activate(GtkApplication *app, gpointer user){
    GtkWidget *window;

    // Creating new window
    window = gtk_application_window_new(app);
    // Setting titles
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    // Seetting the default size for window
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);

    // Adding tool bars into the window
    GtkWidget *toolbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_widget_set_halign(toolbar, GTK_ALIGN_START);
    gtk_widget_set_valign(toolbar, GTK_ALIGN_START);
    GtkWindow *windows_get = GTK_WINDOW(window);

    // Setting names of the widget to "toolbar"
    gtk_widget_set_name(toolbar, "toolbar");
    // Adding css provider
    GtkCssProvider *cssProvider =  gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "theme.css");
    GtkStyleContext *toolbar_css_context = gtk_widget_get_style_context(toolbar);
    gtk_style_context_add_provider(toolbar_css_context, GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Create button
    // File Button
    GtkWidget *file_button = gtk_button_new_with_label("File");
    gtk_box_append(GTK_BOX(toolbar), file_button);

    // Edit Button
    GtkWidget *edit_button = gtk_button_new_with_label("Edit");
    gtk_box_append(GTK_BOX(toolbar), edit_button);

    // Selection Button
    GtkWidget *selection_button = gtk_button_new_with_label("Selection");
    gtk_box_append(GTK_BOX(toolbar), selection_button);

    // View button
    GtkWidget *view = gtk_button_new_with_label("View");
    gtk_box_append(GTK_BOX(toolbar), view);

    // Terminal button
    GtkWidget *terminal = gtk_button_new_with_label("Terminal");
    gtk_box_append(GTK_BOX(toolbar), terminal);

    // change position
    gtk_window_set_child(windows_get, toolbar);
    gtk_window_present(windows_get);
}

// Starting application of the GTK application
int main (int argc, char **argv){
    GtkApplication *app;

    int status;

    // Setting a new application
    app = gtk_application_new("testing.test.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    // Run window
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;

}
