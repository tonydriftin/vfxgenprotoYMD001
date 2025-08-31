import SwiftUI
import MetalKit

struct MetalView: UIViewRepresentable {
    func makeUIView(context: Context) -> MTKView { MTKView() }
    func updateUIView(_ uiView: MTKView, context: Context) {}
}
