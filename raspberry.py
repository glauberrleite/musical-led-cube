
r = [3,8,13,18];
b = [5,11,15,19];
g = [7,12,16,21];
ground = [29,30,31,32];
level = [22,23,24,26];

#Define biblioteca da GPIO
import RPi.GPIO as GPIO

#Define biblioteca de tempo
import time
GPIO.setmode(GPIO.BOARD)

#Define pinos da placa como saida
for i in range (1,4):
    GPIO.setup(r[i], GPIO.OUT)
    GPIO.setup(b[i], GPIO.OUT)
    GPIO.setup(g[i], GPIO.OUT)
    GPIO.setup(ground[i], GPIO.OUT)
    GPIO.setup(level[i], GPIO.OUT)

def setColumnColor(column, r, g, b):
    GPIO.output(r[column], r);
    GPIO.output(g[column], g);
    GPIO.output(b[column], b);

def setLevel(l, state):
    GPIO.output(level[l], state);

def setRow(row, state):
    GPIO.output(ground[row], state);

def alternateLevel(level):
    for i in range (1:4):
        if i == level:
            setLevel(i,HIGH);
        else:
            setLevel(i,LOW);
