#!/usr/bin/env python

import pygame

class Game:
    def __init__(self, layout):
        self.__scr = layout

        self.__bg = pygame.image.load('background.jpg')

        self.__player_up = pygame.image.load('meca_head_down_01.png')
        self.__player_down = pygame.image.load('meca_weels_down_01.png')
        self.__player_x = 640
        self.__player_y = 400
        self.__player_vx = 0
        self.__player_vy = 0

    def run(self):
        
         while 1:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    return
                elif (event.type == pygame.KEYDOWN and
                      event.key == pygame.K_ESCAPE):
                    return

                # Player control
                elif (event.type == pygame.KEYDOWN and
                      event.key == pygame.K_UP):
                    self.__player_vy = -1
                elif (event.type == pygame.KEYDOWN and
                      event.key == pygame.K_DOWN):
                    self.__player_vy = +1
                elif (event.type == pygame.KEYDOWN and
                      event.key == pygame.K_LEFT):
                    self.__player_vx = -1
                elif (event.type == pygame.KEYDOWN and
                      event.key == pygame.K_RIGHT):
                    self.__player_vx = +1

                elif (event.type == pygame.KEYUP and
                      event.key == pygame.K_UP and self.__player_vy == -1):
                    self.__player_vy = 0
                elif (event.type == pygame.KEYUP and
                      event.key == pygame.K_DOWN and self.__player_vy == 1):
                    self.__player_vy = 0
                elif (event.type == pygame.KEYUP and
                      event.key == pygame.K_LEFT and self.__player_vx == -1):
                    self.__player_vx = 0
                elif (event.type == pygame.KEYUP and
                      event.key == pygame.K_RIGHT and self.__player_vx == 1):
                    self.__player_vx = 0

            self.__player_x += self.__player_vx
            self.__player_y += self.__player_vy

            # Draw everything
            self.__scr.blit(self.__bg, (0, 0))
            self.__scr.blit(self.__player_down,
                            (self.__player_x, self.__player_y + 10))
            self.__scr.blit(self.__player_up,
                            (self.__player_x, self.__player_y))
            pygame.display.flip()


# TEST CODE
def main():
    pygame.init()
    screen = pygame.display.set_mode((1024, 768), pygame.FULLSCREEN)
    game = Game(screen)
    game.run()

if __name__ == '__main__':
    main()
