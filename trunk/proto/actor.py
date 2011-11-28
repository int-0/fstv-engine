#!/usr/bin/env python
#

import pygame
from action import Action

class Actor:
    def __init__(self, layer, initial_animation, position = (0, 0)):
        # For now we use vector of actions, the best way is dict of actions
        # with action_name as key. But this solution is faster :)
        self.actions = [initial_animation]
        self.current = 0

        self.position = position

        self.layer = layer

    def add_action(self, animation):
        self.actions.append(animation)

    # FIXME: check range!
    def set_action(self, action):
        self.actions[self.current].reset()
        self.current = action

    def update(self):
        return [self.layer.blit(self.actions[self.current].update(),
                                self.position)]

class KilledActor:
    def __init__(self, layer, animation, position = (0, 0)):
        self.layer = layer

        self.animation = animation

        self.__size = len(self.animation.frame)
        self.destroy = False

    def update(self):
        if self.animation.current_frame < self.__size:
            return [self.layer.blit(self.animation.update(),
                                    self.position)]
        
        self.destroy = True
        return [self.layer.blit(self.animation.frame[self.animation.current_frame],
                                self.position)]


