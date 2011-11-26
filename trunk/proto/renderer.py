#!/usr/bin/env python

import pygame

class Renderer:
    def __init__(self, layer):
        self.__layer = layer
        self.__background = pygame.Surface((self.__layer.get_rect().width,
                                            self.__layer.get_rect().height))

        self.actor = {}
        self.player = {}

    def set_background(self, background):
        self.__background = background

    def add_actor(self, aid, actor):
        actor.layer = self.__layer
        self.__actor[aid] = actor

    def remove_actor(self, aid):
        if self.__actor.has_key(aid):
            del(self.__actor[aid])

    def add_players(self, pid, player):
        player.layer = self.__layer
        self.__player[pid] = player
        
    def remove_player(self, pid):
        if self.__player.has_key(pid):
            del(self.__player[pid])

    def update(self):
        changes = []
        self.__layer.blit(self.__background, (0, 0))
        for actor in self.__actor.values():
            changes += actor.update()
        for player in self.__player.values():
            changes += player.update()
        return changes
