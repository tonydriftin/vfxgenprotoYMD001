# Motion VFX Generator (Mobile + macOS)
**Real-time, motion-reactive VFX for 10–30s clips.**  
GPU-accelerated effects (Metal/GLES), optical flow + pose tracking, and a “Never-Twice” procedural engine so no two renders are the same.

<p align="left">
  <img alt="license" src="https://img.shields.io/badge/license-MIT-informational">
  <img alt="platforms" src="https://img.shields.io/badge/platforms-iOS%20%7C%20Android%20%7C%20macOS-blue">
  <img alt="build" src="https://img.shields.io/badge/build-C%2B%2B17%20%7C%20Metal%20%7C%20GLES3-success">
</p>

https://user-images.example/demo.gif

---

## ✨ What it is
A cross-platform engine that ingests video, analyzes motion in real time, and generates **motion-based** VFX (fire, glitch, paper-cut, particles, trails, shockwaves). Built for creators on low-end phones and **Apple Silicon** Macs.

**Highlights**
- **Motion analysis**: fast ROI detection → dense optical flow / LK tracks (ROI-only), optional pose/segmentation
- **GPU VFX graph**: distortion, particles, toon/halftone, vector trails, shockwaves — all real time
- **“Never-Twice” generator**: seeded procedural DNA + constraints ⇒ unique, non-repeating results
- **Performance-first**: zero-copy decode/encode (VideoToolbox/MediaCodec), ring buffers, multi-res flow
- **Export**: MP4/H.264+HEVC; macOS supports ProRes and effect-only overlays (HEVC-alpha/ProRes4444)

---

## 🧱 Architecture
```text
[Decoder HW] → [Tier-A Motion (cheap, 5–10fps, low-res)] → ROIs
                                      └─→ [Tier-B Flow/Pose (ROI-only)]
                                                 ↓
                                   [GPU Effect Graph (Metal/GLES)]
                                                 ↓
                                        [Compositor → Encoder HW]
