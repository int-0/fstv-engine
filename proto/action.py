#!/usr/bin/env python

import os.path
import pygame
import common

class FrameStack:
    def __init__(self, base_filename = None):
        self.frame = []

        # Load frames
        if not base_filename is None:
            self.__load_frames(base_filename)

    def __filenames(self, basename):
        for frame_n in range(1, 100):
            filename = basename + '%02d' % frame_n + '.png'
            yield filename

    def __load_frames(self, basename):
        for filename in self.__filenames(basename):
            if not os.path.exists(filename):
                break
            frame = common.load_image(filename)
            self.frame.append(frame)

    def vflip(self):
        animation = FrameStack()
        for frm in self.frame:
            animation.frame.append(pygame.transform.flip(frm, 1, 0))
        return animation

    def hflip(self):
        animation = FrameStack()
        for frm in self.frame:
            animation.frame.append(pygame.transform.flip(frm, 0, 1))
        return animation

    def scale(self, scale_factor_x, scale_factor_y = None):
        animation = FrameStack()
        if scale_factor_y is None:
            scale_factor_y = scale_factor_x

        for frm in self.frame:
            resolution = frm.get_rect()
            new_res_x = int(float(resolution.width) * float(scale_factor_x))
            new_res_y = int(float(resolution.height) * float(scale_factor_y))
            animation.frame.append(pygame.transform.scale(frm,
                                                          (new_res_x,
                                                           new_res_y)))
        return animation

class Action:
    def __init__(self, frame_stack):
        self.stack = frame_stack
        self.current_frame = 0

        self.current_frame = 0
        self.__length = len(self.stack.frame)


    def reset(self):
        self.current_frame = 0

    def update(self):
        self.current_frame = (self.current_frame + 1) % self.__length
        return self.stack.frame[self.current_frame]

    def __call__(self):
        return self.stack.frame[self.current_frame]
