#!/usr/bin/env python

import pygame
import math

class Player:
    def __init__(self, scr, pos = (640, 400)):
        self.__frm = { -1 : { -1 : [pygame.image.load('meca_head_leftup_01.png'),
                                    [pygame.image.load('meca_weels_leftup_01.png'),
                                     pygame.image.load('meca_weels_leftup_02.png'),
                                     pygame.image.load('meca_weels_leftup_03.png')]],
                               0 : [pygame.image.load('meca_head_left_01.png'),
                                    [pygame.image.load('meca_weels_left_01.png'),
                                     pygame.image.load('meca_weels_left_02.png'),
                                     pygame.image.load('meca_weels_left_03.png')]],
                               1 : [pygame.image.load('meca_head_leftdown_01.png'),
                                    [pygame.image.load('meca_weels_leftdown_01.png'),
                                     pygame.image.load('meca_weels_leftdown_02.png'),
                                     pygame.image.load('meca_weels_leftdown_03.png')]] },
                        0 : { -1 : [pygame.image.load('meca_head_up_01.png'),
                                    [pygame.image.load('meca_weels_up_01.png'),
                                     pygame.image.load('meca_weels_up_02.png'),
                                     pygame.image.load('meca_weels_up_03.png')]],
                               0 : [pygame.image.load('meca_head_down_01.png'),
                                    [pygame.image.load('meca_weels_down_01.png'),
                                     pygame.image.load('meca_weels_down_02.png'),
                                     pygame.image.load('meca_weels_down_03.png')]],
                               1 : [pygame.image.load('meca_head_down_01.png'),
                                    [pygame.image.load('meca_weels_down_01.png'),
                                     pygame.image.load('meca_weels_down_02.png'),
                                     pygame.image.load('meca_weels_down_03.png')]] },
                        1 : { -1 : [pygame.image.load('meca_head_rightup_01.png'),
                                    [pygame.image.load('meca_weels_rightup_01.png'),
                                     pygame.image.load('meca_weels_rightup_02.png'),
                                     pygame.image.load('meca_weels_rightup_03.png')]],
                               0 : [pygame.image.load('meca_head_right_01.png'),
                                    [pygame.image.load('meca_weels_right_01.png'),
                                     pygame.image.load('meca_weels_right_02.png'),
                                     pygame.image.load('meca_weels_right_03.png')]],
                               1 : [pygame.image.load('meca_head_rightdown_01.png'),
                                    [pygame.image.load('meca_weels_rightdown_01.png'),
                                     pygame.image.load('meca_weels_rightdown_02.png'),
                                     pygame.image.load('meca_weels_rightdown_03.png')]]
                               }
                        }
        self.__weel = 1
        self.__pos = pos
        self.vx = 0
        self.vy = 0
        self.__xdir = 0
        self.__ydir = 0
        self.__scr = scr

    def set_vx(self, vx):
        if ((vx == 0) and (self.vy == 0)):
            self.__frm[0][0][0] = self.__frm[self.__xdir][0][0]
            self.__frm[0][0][1] = self.__frm[self.__xdir][0][1]
        self.vx = vx
        if vx != 0:
            self.__xdir = int(self.vx / abs(self.vx))
        else:
            self.__xdir = 0

    def set_vy(self, vy):
        if ((self.vx == 0) and (vy == 0)):
            self.__frm[0][0][0] = self.__frm[0][self.__ydir][0]
            self.__frm[0][0][1] = self.__frm[0][self.__ydir][1]
        self.vy = vy
        if vy != 0:
            self.__ydir = int(self.vy / abs(self.vy))
        else:
            self.__ydir = 0

    def get_xdir(self):
        return self.__xdir

    def get_ydir(self):
        return self.__ydir

    def update(self):
        self.__pos = (self.__pos[0] + self.vx, self.__pos[1] + self.vy)
        if ((self.__xdir != 0) or (self.__ydir != 0)):
            self.__weel = (self.__weel + 1) % len(self.__frm[self.__xdir][self.__ydir][1])
        self.__scr.blit(self.__frm[self.__xdir][self.__ydir][1][self.__weel], (self.__pos[0], self.__pos[1] + 10))
        self.__scr.blit(self.__frm[self.__xdir][self.__ydir][0], self.__pos)
        
class Game:
    def __init__(self, layout):
        self.__scr = layout
        self.__player = Player(self.__scr)
        self.__bg = pygame.image.load('background.jpg')

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
                    self.__player.set_vy(-2)
                elif (event.type == pygame.KEYDOWN and
                      event.key == pygame.K_DOWN):
                    self.__player.set_vy(2)
                elif (event.type == pygame.KEYDOWN and
                      event.key == pygame.K_LEFT):
                    self.__player.set_vx(-2)
                elif (event.type == pygame.KEYDOWN and
                      event.key == pygame.K_RIGHT):
                    self.__player.set_vx(2)

                elif (event.type == pygame.KEYUP and
                      event.key == pygame.K_UP and self.__player.get_ydir() == -1):
                    self.__player.set_vy(0)
                elif (event.type == pygame.KEYUP and
                      event.key == pygame.K_DOWN and self.__player.get_ydir() == 1):
                    self.__player.set_vy(0)
                elif (event.type == pygame.KEYUP and
                      event.key == pygame.K_LEFT and self.__player.get_xdir() == -1):
                    self.__player.set_vx(0)
                elif (event.type == pygame.KEYUP and
                      event.key == pygame.K_RIGHT and self.__player.get_xdir() == 1):
                    self.__player.set_vx(0)

            # Draw everything
            self.__scr.blit(self.__bg, (0, 0))
            self.__player.update()
            pygame.display.flip()


# TEST CODE
def main():
    pygame.init()
    screen = pygame.display.set_mode((1024, 768), pygame.FULLSCREEN)
    game = Game(screen)
    game.run()

if __name__ == '__main__':
    main()
