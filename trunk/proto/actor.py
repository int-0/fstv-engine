#!/usr/bin/env python
#

from actor import Actor
import pygame

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
        return [layer.blit(self.actions[self.current].update(),
                           self.position)]
