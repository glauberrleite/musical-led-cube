import scipy.io.wavfile
import matplotlib.pyplot as pyplot


class Spectrum():
    def __init__(self, sample):
        self.samplerate, self.data = scipy.io.wavfile.read(sample)

    def plot(self):
        N = 4 * self.samplerate
        x = scipy.fft(self.data[:N])
        gain = 20 * scipy.log10(scipy.absolute(x))
        f = scipy.linspace(0, self.samplerate, N, endpoint=False)
        pyplot.plot(f, gain)
        pyplot.xlim(0, 5000)
        pyplot.show()


def main():
    print("Drawing sample...")
    sample = Spectrum("sample.wav")
    sample.plot()

if __name__ == '__main__':
    main()
