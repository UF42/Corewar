#include "visualizer.h"

void			sdl_putnbr(t_nbrinfo rnbr, SDL_Rect clip, t_arena *arena)
{
	SDL_Point	top_left;
	int			figure_count;
	int			tmp;
	int			figure_width;
	int			figure_height;

	tmp = rnbr.nbr;
	figure_count = 1;
	while ((tmp /= 10))
		figure_count++;
	if (figure_count < rnbr.min_width)
		figure_count = rnbr.min_width;
	figure_height = clip.h;
	figure_width = clip.w / figure_count;
	top_left.x = clip.x + clip.w - figure_width;
	top_left.y = clip.y;
	while (figure_count--)
	{
		int figure = rnbr.nbr % 10;
		rnbr.nbr /= 10;
		SDL_Rect r = get_rectangle(0, 0, figure_width, figure_height);
		t_rposition pos = get_render_position(0, top_left, top_left, (SDL_Point){.x = r.w, .y = r.h});
		set_color(rnbr.c, arena->bold_figures[figure]);
		render(pos, arena->bold_figures[figure], arena->renderer, SDL_FLIP_NONE);
		top_left.x -= figure_width;
	}
}