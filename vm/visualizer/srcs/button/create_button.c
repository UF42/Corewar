#include "visualizer.h"

static inline void	create_button_text(t_button *btn,
										SDL_Renderer *renderer,
										const char *text)
{
	SDL_Point		txt_top_left;
	t_ltexture		*texture;

	if (text != NULL)
	{
		txt_top_left.x = btn->position.x + btn->width / 4;
		txt_top_left.y = btn->position.y;
		texture = load_from_rendered_text(get_text_info(WESTERN_SWING,
											btn->width,
											text,
											(SDL_Color){.r = 0, .g = 0, .b = 0, .a = 0}),
											renderer);
		btn->button_txt = texture;
		btn->txt_position = txt_top_left;
	}
	else
	{
		btn->button_txt = NULL;
	}
}

t_button		*create_button(double angle,
								SDL_Point position,
								const char *text,
								SDL_Renderer *renderer,
								SDL_Point params)
{
	t_button	*new_btn;

	new_btn = NULL;
	if (!(new_btn = (t_button *)malloc(sizeof(t_button))))
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
									"Error!",
									"Bad allocation",
									NULL);
	else
	{
		new_btn->width = params.x;
		new_btn->height = params.y;
		new_btn->position = position;
		new_btn->current_sprite = 0;
		new_btn->clip = get_rectangle(new_btn->position.x,
									new_btn->position.y,
									new_btn->width,
									new_btn->height);
		new_btn->btn_pos =
			get_render_position(angle,
								&(new_btn->position),
								NULL,
								&(new_btn->clip));
		create_button_text(new_btn, renderer, text);
	}
	return (new_btn);
}