#include <print>
#include <chrono>

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
void update(double delta_time)
{
  std::println("call every update fps {:.0f}", 1.f / delta_time);
}
void renderer()
{
  std::println("call every renderer");
}

int main()
{
  GameState game_state = {.width= 800, .height=600, .is_running = true};
  
  init();

  auto last_time = std::chrono::steady_clock::now();

  while(game_state.is_running)
  {
      auto current_time = std::chrono::steady_clock::now();
      std::chrono::duration<double> elapsed = current_time - last_time;
      last_time = current_time;
      
      double delta_time = elapsed.count();
      
      update(delta_time);
      
      renderer();
  }
}
