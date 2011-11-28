#!/usr/bin/env python

import pygame

def load_image(fullname):
    try:
        image = pygame.image.load(fullname)
    except pygame.error, message:
        print 'Cannot load image:', fullname
        raise SystemExit, message
    return image.convert_alpha()
