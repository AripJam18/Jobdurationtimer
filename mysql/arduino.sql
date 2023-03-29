-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Waktu pembuatan: 29 Mar 2023 pada 10.40
-- Versi server: 10.4.6-MariaDB
-- Versi PHP: 7.3.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `arduino`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `jobdurationtimer`
--

CREATE TABLE `jobdurationtimer` (
  `id` int(11) NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `duration` varchar(8) NOT NULL,
  `remarks` varchar(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data untuk tabel `jobdurationtimer`
--

INSERT INTO `jobdurationtimer` (`id`, `timestamp`, `duration`, `remarks`) VALUES
(402, '2023-03-29 07:07:03', '00:01:16', 'Good'),
(403, '2023-03-29 07:16:29', '00:02:44', 'Good'),
(404, '2023-03-29 07:25:57', '00:09:05', 'Good'),
(405, '2023-03-29 07:47:10', '00:20:33', 'Late'),
(406, '2023-03-29 07:48:18', '00:00:16', 'Good'),
(407, '2023-03-29 07:48:19', '00:00:16', 'Good'),
(408, '2023-03-29 08:06:21', '00:07:35', 'Good'),
(409, '2023-03-29 08:18:36', '00:11:49', 'Good'),
(410, '2023-03-29 08:39:27', '00:18:36', 'Late');

--
-- Indexes for dumped tables
--

--
-- Indeks untuk tabel `jobdurationtimer`
--
ALTER TABLE `jobdurationtimer`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT untuk tabel yang dibuang
--

--
-- AUTO_INCREMENT untuk tabel `jobdurationtimer`
--
ALTER TABLE `jobdurationtimer`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=411;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
