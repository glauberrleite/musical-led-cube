import scipy.io.wavfile
import matplotlib.pyplot as pyplot

samplerate, data = scipy.io.wavfile.read("sample.wav")

N = 4*samplerate
x = scipy.fft(data[:N])

gain = 20*scipy.log10(scipy.absolute(x))

f = scipy.linspace(0, samplerate, N, endpoint=False)

pyplot.plot(f, gain)

pyplot.xlim(0, 5000)

pyplot.show()
