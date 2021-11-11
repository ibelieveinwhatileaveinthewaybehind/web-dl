# hbo max downloader, modify to your needs!
# v1.0
# get a copy of yt-dlp and mp4decrypt in the same directory as this script and you should be good!

import os, subprocess

mpd = input("Enter the mpd url: ")
ak = input("Enter the first key (usually audio) [kid:key]: ")
vk = input("Enter the second key (usually video) [kid:key]: ")
subprocess.run(f"yt-dlp.exe --allow-unplayable-formats \"{mpd}\" -o video.mp4 -f \"bestvideo[height<=?1080][tbr>11000]\"")
subprocess.run(f"mp4decrypt.exe --key {vk} video.mp4 vd.mp4")
os.remove("video.mp4")
subprocess.run(f"yt-dlp.exe --allow-unplayable-formats \"{mpd}\" -o english.mp4 -f \"bestaudio[tbr>300][language=en-US]")
subprocess.run(f"mp4decrypt.exe --key {ak} english.mp4 en.mp4")
os.remove("english.mp4")
subprocess.run(f"yt-dlp.exe --allow-unplayable-formats \"{mpd}\" -o spanish.mp4 -f \"bestaudio[tbr>300][language=es-419]")
subprocess.run(f"mp4decrypt.exe --key {ak} spanish.mp4 sp.mp4")
os.remove("spanish.mp4")
subprocess.run(f"yt-dlp.exe --allow-unplayable-formats \"{mpd}\" -o portugese.mp4 -f \"bestaudio[tbr>300][language=pt-BR]")
subprocess.run(f"mp4decrypt.exe --key {ak} portugese.mp4 pt.mp4")
os.remove("portugese.mp4")