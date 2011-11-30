#!/usr/bin/env python

import pygame

class Renderer:
    def __init__(self, layer):
        self.__layer = layer
        self.__background = pygame.Surface((self.__layer.get_rect().width,
                                            self.__layer.get_rect().height))
        self.__background.convert_alpha()

        self.actor = {}
        self.killed_actor = []
        self.player = {}

    def set_background(self, background):
        self.__background = background

    def add_actor(self, aid, actor):
        actor.layer = self.__layer
        self.__actor[aid] = actor

    def remove_actor(self, aid):
        if self.__actor.has_key(aid):
            del(self.__actor[aid])

    def add_killed_actor(self, killed_actor):
        killed_actor.layer = self.__layer
        self.killed_actor.append(killed_actor)

    def add_players(self, pid, player):
        player.layer = self.__layer
        self.player[pid] = player
        
    def remove_player(self, pid):
        if self.player.has_key(pid):
            del(self.player[pid])

    def update(self):
        changes = []
        self.__layer.blit(self.__background, (0, 0))
        for actor in self.actor.values():
            changes += actor.update()
        for player in self.player.values():
            changes += player.update()

        remove_actors = []
        for kill_actor in self.killed_actor:
            changes += kill_actor.update()
            if kill_actor.destroy:
                remove_actors.append(self.killed_actor.index(kill_actor))
        for actor in remove_actors:
            del(self.killed_actor[actor])
            
        return changes
