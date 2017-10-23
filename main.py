import scipy.io.wavfile

samplerate, data = scipy.io.wavfile.read("sample.wav")

N = 4*samplerate
x = scipy.fft(x[:N])

gain = 20*scipy.log10(scipy.absolute(x))

f = scipy.linspace(0, samplerate, N, endpoint=False)

pylab.plot(f, gain)

pylab.xlim(0, 5000)
