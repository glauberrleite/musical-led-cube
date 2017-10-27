import scipy.io.wavfile
import matplotlib.pyplot as pyplot
import matplotlib.animation

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

def animate(i):
    start = int(round(i * samplerate))
    end = int(round((i + STEP) * samplerate))

    fourier = scipy.fft(data[start:end])

    gain = 20*scipy.log10(scipy.absolute(fourier))

    freq = scipy.linspace(0, samplerate, STEP*samplerate, endpoint=False)

    line.set_data(freq, gain)

    return line,


anim = matplotlib.animation.FuncAnimation(fig, animate, frames=int(round(duration/STEP)), interval=(STEP * 1000), blit=True)

pyplot.show()
