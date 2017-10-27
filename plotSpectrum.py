import scipy.io.wavfile
import matplotlib.pyplot as pyplot
from scipy.fftpack import fft
import math as math
import numpy as numpy


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

    def plotChannels(self):
        sound = self.data
        sound = sound / (2.**15) #convert sound array to float pt. values
        sound1 = sound[:,0] #left channel
        sound2 = sound[:,1] #right channel

        num1 = len(sound1)
        fourierLeft = fft(sound1)

        num2 = len(sound2)
        fourierRight = fft(sound2)

        num1UniquePts = math.ceil((num1 + 1) / 2.0)
        fourierLeft = fourierLeft[0:int(num1UniquePts)]
        fourierLeft = abs(fourierLeft)

        num2UniquePts = math.ceil((num2 + 1)/2.0)
        fourierRight = fourierRight[0:int(num2UniquePts)]
        fourierRight = abs(fourierRight)

        ''' Left Channel '''
        fourierLeft = fourierLeft / float(num1)
        fourierLeft = fourierLeft**2

        if num1 % 2 > 0:  # we've got odd number of points fft
            fourierLeft[1:len(fourierLeft)] = fourierLeft[1:len(fourierLeft)] * 2
        else:
            fourierLeft[1:len(fourierLeft) - 1] = fourierLeft[1:len(fourierLeft) - 1] * 2  # we've got even number of points fft

        freqArray = numpy.arange(0, num1UniquePts, 1.0) * (self.sampleRate / num1);
        pyplot.plot(freqArray / 1000, 10 * scipy.log10(fourierLeft), color='k')
        pyplot.xlabel('LeftChannel_Frequency (kHz)')
        pyplot.ylabel('LeftChannel_Power (dB)')
        pyplot.show()

        '''
        Right Channel
        '''
        fourierRight = fourierRight / float(num2)  # scale by the number of points so that
        # the magnitude does not depend on the length
        # of the signal or on its sampling frequency
        fourierRight = fourierRight ** 2  # square it to get the power

        # multiply by two (see technical document for details)
        # odd nfft excludes Nyquist point
        if num2 % 2 > 0:  # we've got odd number of points fft
            fourierRight[1:len(fourierRight)] = fourierRight[1:len(fourierRight)] * 2
        else:
            fourierRight[1:len(fourierRight) - 1] = fourierRight[1:len(fourierRight) - 1] * 2  # we've got even number of points fft

        freqArray2 = numpy.arange(0, num2UniquePts, 1.0) * (self.sampleRate / num2);
        pyplot.plot(freqArray2 / 1000, 10 * scipy.log10(fourierRight), color='k')
        pyplot.xlabel('RightChannel_Frequency (kHz)')
        pyplot.ylabel('RightChannel_Power (dB)')
        pyplot.show()


def main():
    print("Drawing sample...")
    sample = Spectrum("sample.wav")
    sample.plotChannels()
    #sample.plot()
    #sample.fastFourier()

if __name__ == '__main__':
    main()
