
#include <bitset>
#include <iostream>

int main(int argc, char *argv[]) {
  // SDL_Window *window;
  // SDL_Renderer *renderer;
  // SDL_Event event;
  //
  // if (SDL_Init(SDL_INIT_VIDEO) < 0) {
  //   SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s",
  //                SDL_GetError());
  //   return 3;
  // }
  //
  // if (SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_RESIZABLE, &window,
  //                                 &renderer)) {
  //   SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
  //                "Couldn't create window and renderer: %s", SDL_GetError());
  //   return 3;
  // }
  //
  // while (1) {
  //   SDL_PollEvent(&event);
  //   if (event.type == SDL_QUIT) {
  //     break;
  //   }
  //   SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
  //   SDL_RenderClear(renderer);
  //   SDL_RenderPresent(renderer);
  // }
  //
  // SDL_DestroyRenderer(renderer);
  // SDL_DestroyWindow(window);
  //
  // SDL_Quit();
  //
  uint8_t registers[16]{};

  registers[0] = 5;   // Store the value 5 in the first register
  registers[1] = 10;  // Store the value 10 in the second register
  registers[2] = 255; // Store the value 255 in the third register (maximum

  // Example of accessing the values
  std::cout << "register 0: " << static_cast<int>(registers[0]) << std::endl;
  std::cout << "register 1: " << static_cast<int>(registers[1]) << std::endl;
  std::cout << "register 2: " << static_cast<int>(registers[2]) << std::endl;

  printf("\n");

  std::cout << "register 0: " << std::bitset<8>(registers[0]) << std::endl;
  std::cout << "register 1: " << std::bitset<8>(registers[1]) << std::endl;
  std::cout << "register 2: " << std::bitset<8>(registers[2]) << std::endl;

  return 0;
}
