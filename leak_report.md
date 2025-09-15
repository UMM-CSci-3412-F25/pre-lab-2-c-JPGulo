# Leak report

Leaks Found:
*is_clean calling strip returns a heap string that was not freed, fixed
by freeing the buffer inside is_clean after strcmp.
*Tests called strip and didn't free the returned heap strings, fixed
by storing pointer, asserting equals, and calling free.
*Also, if (num >= size) {
        return "";
}
doesn't always return a heap string which causes problems,
somtimes strip gave a heap or "" which one you need to free and 
the other you don't free. So it was fixed by making it always needing
to be freed, strip would always give you a heap string and it will
always be freed.