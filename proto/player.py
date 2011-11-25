#!/usr/bin/env python
#

from action import Action
import pygame

class Player:
    def __init__(self,
                 layer
                 initial_top_animation, initial_bottom_animation,
                 bottom_offsets = (0, 0), position = (0, 0)):
        # For now we use vector of actions, the best way is dict of actions
        # with action_name as key. But this solution is faster :)
        self.top_actions = [initial_top_animation]
        self.bot_actions = [initial_bot_animation]

        self.top_cur = 0
        self.bot_cur = 0

        self.offset = bottom_offsets
        self.position = position

        self.layer = layer

    def add_action(self, animation):
        self.actions.append(animation)

    # FIXME: check range!
    def set_top_action(self, action):
        self.top_actions[self.top_cur].reset()
        self.top_cur = action

    # FIXME: check range!
    def set_bottom_action(self, action):
        self.bot_actions[self.bot_cur].reset()
        self.bot_cur = action

    def update(self):
        return [layer.blit(self.top_actions[self.top_cur].update(),
                           self.position),
                layer.blit(self.bot_actions[self.bot_cur].update(),
                           (self.position[0] + self.offset[0],
                            self.position[1] + self.offset[1]))]
