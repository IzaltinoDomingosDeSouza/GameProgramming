#include <print>
#include <chrono>

struct GameState
{
  uint32_t width;
  uint32_t height;
  float target_fps;
  bool is_running;
};

void init()
{
  std::println("call once");
}
void update(double delta_time)
{
  std::println("call every update {}", delta_time);
}
void renderer()
{
  std::println("call every renderer");
}

int main()
{
  GameState game_state = {.width= 800, .height=600, .target_fps = 30.0, .is_running = true};
  
  init();
  
  const double target_delta_time = (1.0 / game_state.target_fps);
  double accumulated_time = 0.0;

  auto last_time = std::chrono::steady_clock::now();

  while(game_state.is_running)
  {
      auto current_time = std::chrono::steady_clock::now();
      std::chrono::duration<double> elapsed = current_time - last_time;
      last_time = current_time;
      
      double delta_time = elapsed.count();
      
      if (delta_time > 0.25) delta_time = 0.25; 
      
      accumulated_time += delta_time;
      
      while(accumulated_time >= target_delta_time)
      {
          update(target_delta_time);
          accumulated_time -= target_delta_time;
      }
      
      renderer();
  }
}
