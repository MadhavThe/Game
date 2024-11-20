//#include "Renderer.hpp"
//
//void drawCircle(SDL_Renderer* renderer, int cX, int cY, int r) {
//    int x = r, y = 0, d = 1 - x;
//    while (y <= x) {
//        SDL_Point points[8] = {
//            {cX - x, cY - y}, {cX - x, cY + y}, {cX + x, cY - y}, {cX + x, cY + y},
//            {cX - y, cY - x}, {cX - y, cY + x}, {cX + y, cY - x}, {cX + y, cY + x}
//        };
//        SDL_RenderDrawPoints(renderer, points, 8);
//        y++;
//        d += (d <= 0) ? 2 * y + 1 : 2 * (y - x--) + 1;
//    }
//}
//
//void render(SDL_Renderer* renderer, SDL_Rect& rect, SDL_Rect& rect1) {
//    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
//    SDL_RenderClear(renderer);
//
//    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
//    SDL_RenderFillRect(renderer, &rect);
//
//    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//    SDL_RenderFillRect(renderer, &rect1);
//
//    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    SDL_Point points[5] = { {100, 300}, {200, 400}, {300, 300}, {400, 400}, {500, 300} };
//    SDL_RenderDrawLines(renderer, points, 5);
//
//    drawCircle(renderer, 300, 300, 100);
//    SDL_RenderPresent(renderer);
//}
