import scipy.io.wavfile
import matplotlib.pyplot as pyplot
import matplotlib.animation
from scipy.fftpack import fft
import math as math
import numpy as numpy

# Reading audio file and collecting its relevant info
samplerate, data = scipy.io.wavfile.read("sample.wav")
duration = len(data)/samplerate

# Setting STEP for the number of seconds for delay
# and n for the corresponding number of frames in data array
STEP = 1
N = STEP * samplerate

# Preparing graph
fig = pyplot.figure()
ax = pyplot.axes(xlim=(0, 5000), ylim=(75, 175))
line, = ax.plot([], [])

# Setting frequency axis
freq = scipy.linspace(0, samplerate, N, endpoint=False)

# Defining animation function where i is the frame
def animate(i):
    start = int(round(i * samplerate))
    end = int(round((i + STEP) * samplerate))

    # Applying Fast Fourier Transform
    fourier = scipy.fft(data[start:end])

    # Calculating gain to work in dB
    gain = 20*scipy.log10(scipy.absolute(fourier))

    # Building gain/frequency plot for this frame
    line.set_data(freq, gain)

    return line,


anim = matplotlib.animation.FuncAnimation(fig, animate, frames=int(round(duration/STEP)), interval=(STEP * 1000), blit=True)

class Spectrum():
    def __init__(self, sample):
        self.sampleRate, self.data = scipy.io.wavfile.read(sample)

    def plot(self):
        N = 4 * self.sampleRate
        x = scipy.fft(self.data[:N])
        gain = 20 * scipy.log10(scipy.absolute(x))
        f = scipy.linspace(0, self.sampleRate, N, endpoint=False)
        pyplot.plot(f, gain)
        pyplot.xlim(0, 5000)
        pyplot.show()

    def fastFourier(self):
        a = self.data.T[0] #get the first track of the sound
        b=[(i/2**8.)*2-1 for i in a] # normalizing b in [-1,1)
        c = fft(b)
        d = len(c)/2 #get the real signal symmetry
        pyplot.plot(abs(c[:(d-1)]), 'r')
        pyplot.show()

def main():
    print("Drawing sample...")
    sample = Spectrum("sample.wav")
    sample.plotChannels()
    #sample.plot()
    #sample.fastFourier()

if __name__ == '__main__':
    main()
