/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#![no_std]
#![no_main]

use embedded_graphics::{
    image::{Image, ImageRaw},
    pixelcolor::BinaryColor,
    prelude::Point,
    Drawable,
};
use panic_halt as _;
use ssd1306::{
    mode::DisplayConfig, rotation::DisplayRotation,
    size::DisplaySize128x64, I2CDisplayInterface, Ssd1306,
};

#[arduino_hal::entry]
fn main() -> ! {
    let peripherals = arduino_hal::Peripherals::take().unwrap();
    let pins = arduino_hal::pins!(peripherals);

    let i2c = arduino_hal::I2c::new(
        peripherals.TWI,
        pins.d20.into_pull_up_input(),
        pins.d21.into_pull_up_input(),
        57600,
    );

    let interface = I2CDisplayInterface::new(i2c);
    let mut screen = Ssd1306::new(
        interface,
        DisplaySize128x64,
        DisplayRotation::Rotate0,
    )
    .into_buffered_graphics_mode();

    screen.init().unwrap();

    let raw: ImageRaw<BinaryColor> =
        ImageRaw::new(include_bytes!("./assets/rust.raw"), 64);

    let image = Image::new(&raw, Point::new(32, 0));
    image.draw(&mut screen).unwrap();

    screen.flush().unwrap();

    loop {}
}
