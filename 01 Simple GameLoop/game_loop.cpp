#include <print>

struct GameState
{
  uint32_t width;
  uint32_t height;
  bool is_running;
};

void init()
{
  std::println("call once");
}
void update(float delta_time)
{
  std::println("call every update");
}
void renderer()
{
  std::println("call every renderer");
}

int main()
{
  GameState game_state = {.width= 800, .height=600, .is_running = true};
  
  init();
  
  while(game_state.is_running)
  {
    update(0.0);
    renderer();
  }
}
