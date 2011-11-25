#!/usr/bin/env python

import pygame

class Action:
    def __init__(self, base_filename = None):
        self.frame = []

        # Load frames
        if not base_filename is None:
            self.__load_frames(base_filename)

        self.__current_frame = 0

    def __load_image(self, fullname):
        try:
            image = pygame.image.load(fullname)
        except pygame.error, message:
            print 'Cannot load image:', fullname
            raise SystemExit, message
        return image.convert_alpha()

    def __filenames(self, basename):
        for frame_n in range(1, 100):
            filename = basename + '%02d' % frame_n + '.png'
            yield filename

    def __load_frames(self, basename):
        for filename in self.__filenames(basename):
            if not os.path.exists(filename):
                break
            frame = self.__load_image(filename)
            self.frame.append(frame)

    def vflip(self):
        animation = Action()
        for frm in self.frame:
            animation.frame.append(pygame.transform.flip(frm, 1, 0))
        return animation

    def hflip(self):
        animation = Action()
        for frm in self.frame:
            animation.frame.append(pygame.transform.flip(frm, 0, 1))
        return animation

    def scale(self, scale_factor_x, scale_factor_y = None):
        animation = Action()
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

    def reset(self):
        self.__current_frame = 0

    def update(self):
        self.__current_frame = (self.__current_frame + 1) % len(self.frame)
        return self.frame[self.__current_frame]

    def __call__(self):
        return self.frame[self.__current_frame]
