# 📸 Image Filter Studio

> A comprehensive C++ image processing application with multiple filters, user authentication, and session management.

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square&logo=cplusplus)
![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)
![Status](https://img.shields.io/badge/Status-Complete-success?style=flat-square)
![OOP](https://img.shields.io/badge/Design%20Pattern-OOP-purple?style=flat-square)

---

## 🎯 Overview

**Image Filter Studio** is a full-featured image processing application built in C++ demonstrating advanced Object-Oriented Programming (OOP) concepts. The application allows users to load images, apply a variety of filters sequentially, and save processed results. It includes a complete user management system with admin controls, session logging, and customer account management.

### Key Features:
- ✨ **10 Professional Image Filters** (Pixel, Spatial, Geometric)
- 👥 **Dual User Roles** (Admin & Customer with role-based access)
- 🔐 **User Authentication** with security features
- 💾 **Data Persistence** (customers, sessions, catalog, blocked users)
- 🎨 **Real-time ASCII Preview** of filters
- 📊 **Session Logging** and history tracking
- 🛡️ **Account Management** with blocking/unblocking

---

## 🏗️ Architecture

### OOP Concepts Demonstrated:

#### **1. Encapsulation**
```cpp
class Pixel {
private:
    int red, green, blue;    // Hidden data
public:
    int getRed() const;      // Controlled access
    void setRed(int r);      // Validation
};
```

#### **2. Inheritance**
```cpp
class Filter { /* Abstract base class */ };
class GrayscaleFilter : public Filter { /* Concrete implementation */ };
class InvertFilter : public Filter { /* Concrete implementation */ };
// ... 8 more filter subclasses
```

#### **3. Polymorphism**
```cpp
vector<Filter*> filterPipeline;
for (auto filter : filterPipeline) {
    filter->apply(image);  // Correct apply() called at runtime
}
```

#### **4. Abstraction**
```cpp
class User {      // Abstract
public:
    virtual void displayMenu() = 0;
    virtual string getUserType() const = 0;
};

class Admin : public User { /* Implementation */ };
class Customer : public User { /* Implementation */ };
```

---

## 🎨 10 Image Filters

### **Pixel-Based Filters**
1. **Grayscale** - Converts image to black & white
2. **Invert** - Creates negative effect
3. **Brightness** - Increases/decreases brightness

### **Complex Filters**
4. **Contrast** - Stretches pixel values (two-pass algorithm)

### **Channel Isolation**
5. **Red Channel** - Shows only red component
6. **Green Channel** - Shows only green component
7. **Blue Channel** - Shows only blue component

### **Spatial Filters**
8. **Box Blur** - Smooths image using 3×3 neighborhood averaging

### **Geometric Filters**
9. **Flip Horizontal** - Mirrors left-to-right
10. **Flip Vertical** - Mirrors top-to-bottom

---

## 📁 Project Structure

```
image-filter-studio/
├── README.md
├── main.cpp
├── Pixel.h / Pixel.cpp
├── Image.h / Image.cpp
├── Filter.h / Filter.cpp
├── Grayscale.h / Grayscale.cpp
├── Invert.h / Invert.cpp
├── Brightness.h / Brightness.cpp
├── Contrast.h / Contrast.cpp
├── Red.h / Red.cpp
├── Green.h / Green.cpp
├── Blue.h / Blue.cpp
├── Box_Blur.h / Box_Blur.cpp
├── Horizontal.h / Horizontal.cpp
├── Vertical.h / Vertical.cpp
├── ImageFile.h / ImageFile.cpp
├── FilterSession.h / FilterSession.cpp
└── Data Files (Created at runtime)
    ├── customers.txt
    ├── catalog.txt
    ├── sessions.txt
    └── blocked_cnics.txt
```

---

## 🚀 Getting Started

### Prerequisites
- C++ 17 or higher
- g++ compiler
- ImageMagick (for converting images) - Optional

### Installation

1. **Clone the repository**
```bash
git clone https://github.com/yourusername/image-filter-studio.git
cd image-filter-studio
```

2. **Compile the project**
```bash
g++ -std=c++17 -o app *.cpp
```

3. **Run the application**
```bash
./app
```

### Converting Images to PPM Format

**Ubuntu/Linux:**
```bash
sudo apt install imagemagick
convert image.jpg output.ppm
```

**macOS:**
```bash
brew install imagemagick
convert image.jpg output.ppm
```

---

## 📖 Usage Guide

### Main Menu
```
===== MAIN MENU =====
1. Admin Login
2. Customer Login
3. Register Customer
4. Exit
```

### Customer Workflow - Register & Login
```
Enter CNIC (13 digits): 1234567890123
Enter Password (9 chars, 1+ upper, 1+ digit): Pass1234
Enter Full Name: Ali Khan
Enter Gender (M/F): M
Enter Phone: 3001234567
Enter City: Karachi
✓ Registration successful!
```

### Process Image
```
1. Load JPG/PNG image
2. Show ASCII preview
3. Build filter pipeline
4. Apply pipeline
5. Save output
6. Logout

1. Load image → test.ppm → ✓ Image loaded
3. Build pipeline → Select 1 (Grayscale) → 4 (Contrast) → 0 (Done)
4. Apply → ✓ Filters applied
5. Save → output.ppm → ✓ Saved
```

### Admin Dashboard
```
Login: CNIC: 0123456, Password: Admin123

Total registered customers: 5
- Block/Unblock customers
- Manage filter status
- View all sessions
```

---

## 🔑 Key Classes

### **Pixel Class**
- Stores RGB values (0-255)
- Getter/setter methods
- ASCII character conversion
- Clamping utility

### **Image Class**
- 2D array of pixels
- Deep copy semantics
- Dynamic memory management
- ASCII preview display

### **Filter Classes**
- Abstract Filter base class
- 10 concrete filter implementations
- apply() method for pixel transformation

### **FilterSession Class**
- Manages filter pipeline
- Sequential filter application
- Pipeline text representation

### **User Classes**
- Abstract User base class
- Admin and Customer subclasses
- Role-based access control

---

## ✨ Advanced OOP Features

✅ **Memory Management**
- Dynamic allocation/deallocation
- Deep copy constructor
- Proper destructor implementation

✅ **Operator Overloading**
- Assignment operator
- Copy semantics

✅ **Polymorphism**
- Virtual functions
- Runtime method resolution

✅ **Abstraction**
- Pure virtual methods
- Interface design

✅ **Encapsulation**
- Private/public/protected access
- Data hiding

---

## 📋 Validation Rules

### CNIC
- Exactly **13 digits**
- Numbers only

### Password
- Exactly **9 characters**
- At least **1 uppercase letter**
- At least **1 digit**

### Account Lock
- **3 failed logins** = Account locked
- Admin can unlock

---

## 🧪 Testing

### Test 1: Create Test Image
```bash
./app → Login → Load image → test.ppm
✓ Creates 100x100 gradient automatically
```

### Test 2: Apply Filters
```bash
Load image → Build pipeline → Select filters
Apply → View result
```

### Test 3: Save & Reload
```bash
Save as result.ppm → Logout → Login → Load result.ppm
✓ Image persists
```

---

## 📊 File Formats

### customers.txt
```
CNIC|Password|FullName|Phone|City|Blocked
1234567890123|Pass1234|Ali Khan|3001234567|Karachi|0
```

### sessions.txt
```
CNIC|Timestamp|FiltersApplied|OutputFile
1234567890123|2024-01-15 10:30:45|Grayscale>Brightness|output.ppm
```

### PPM Image Format
```
P6
100 100
255
[RGB bytes...]
```

---

## 🐛 Troubleshooting

| Issue | Solution |
|-------|----------|
| Image won't load | Convert to PPM: `convert image.jpg output.ppm` |
| Filters not applying | Check FilterSession::apply() is called |
| Compilation error | Run: `g++ -std=c++17 -o app *.cpp` |
| Memory issues | Check destructor implementation |

---

## 📈 Performance

- **Grayscale:** O(W×H)
- **Contrast:** O(2×W×H)
- **Box Blur:** O(9×W×H)
- **Memory:** O(W×H×3) for RGB

---

## 📜 License

MIT License - Free to use and modify

---

## 👨‍💻 Author

Your Name
- 📧 Email: your.email@example.com
- 🐙 GitHub: [@yourusername]

---

## 🎓 Learning Outcomes

This project teaches:
- Object-Oriented Design Principles
- Memory Management in C++
- Design Patterns (Factory, Observer, Manager)
- File I/O Operations
- User Authentication & Security
- Image Processing Algorithms

---

**Made with ❤️ using C++17**
