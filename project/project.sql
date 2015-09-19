-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Aug 17, 2015 at 07:40 PM
-- Server version: 5.5.44-0ubuntu0.14.04.1-log
-- PHP Version: 5.5.9-1ubuntu4.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `project`
--

-- --------------------------------------------------------

--
-- Table structure for table `pio`
--

CREATE TABLE IF NOT EXISTS `pio` (
  `county` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `agency` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `full_name` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `contact_title` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `contact_name` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `phone` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `phone_2` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `email` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `email_2` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `twitter` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `url` varchar(255) COLLATE utf8_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `pio`
--

INSERT INTO `pio` (`county`, `agency`, `full_name`, `contact_title`, `contact_name`, `phone`, `phone_2`, `email`, `email_2`, `twitter`, `url`) VALUES
('', '', '', '', '', '', '', '', '', '', ''),
('County', 'Agency', 'Full Name', 'Contact title', 'Contact name', 'Number', 'phone_2', 'email_1', 'email_2', 'Twitter', 'URL'),
('Miami-Dade', 'American Civil Liberties Union', '', 'Director of Communications', 'Baylor Johnson', '786-363-2737', '', '', 'media@aclufl.org', '@ACLUFL', 'https://miami.aclufl.org/'),
('Miami-Dade', 'American Airlines', '', '', '', '817-967-1577 (8 a.m. - 5:30 p.m.)', '817- 931-1348 (after hours)', 'mediarelations@aa.com', '', '@AmericanAir', 'http://hub.aa.com/en/nr/news'),
('Miami-Dade', 'Amtrak', '', '', '', '202-906-3860', '', '', '', '@Amtrak', 'http://www.amtrak.com/home'),
('Miami-Dade', 'Aventura PD', '', 'Chief of Police', 'Steve Steinberg', '305-466-8966', '305-466-8989 (PIO number)', '', 'ssteinberg@aventurapolice.com', '', 'http://www.cityofaventura.com/index.aspx?page=44'),
('Miami-Dade', 'Baptist Health South Florida', '', 'Corporate Communications', 'Christine Kotler', '786-596-5073', '', '', 'CKotler@baptisthealth.net', '@BaptistHealthSF', 'https://baptisthealth.net/en/media-center/pages/media-contacts.aspx'),
('Miami-Dade', 'Catholic Archdiocese of Miami', '', 'Director of Communications', 'Mary Ross Agosta', '305-762-1043', '305-762-1046', '', 'mragosta@theadom.org', '@CatholicMiami', 'http://www.miamiarch.org/'),
('Miami-Dade', 'Coral Gables PD', '', 'PIO', 'Kelly Denham', '305-460-5403', '', 'kdenham@coralgables.com', '', '@CoralGablesPD', 'http://www.coralgables.com/index.aspx?page=1'),
('Miami-Dade', 'Coral Gables Fire Rescue', '', 'Fire Chief', 'Marc Stolzenberg', '305-460-5571', '', '', 'mstolzenberg@coralgables.com', '', 'http://www.coralgables.com/index.aspx?page=66'),
('Miami-Dade', 'CSX railroad', '', 'Regional contact', 'Kristin Seay', '404-350-5029', '1-855-955-6397', '', 'Kaitlyn_Barrett@csx.com', '@CSX', 'http://www.csx.com/index.cfm/media/contact-us/'),
('Miami-Dade', 'DEA', 'Drug Enforcement Administration', 'Regional contact', 'Raynette Savoy Kornickey', '954-660-4602', '305-224-9850', '', '', '@DEANEWS', 'http://www.dea.gov/divisions/contacts/mia_contact.shtml'),
('Miami-Dade', 'DERM ', 'Department of Environmental Resources', 'Media contact', 'Luis Espinoza', '305-992-8122', '305-372-6770', 'espinl@miamidade.gov', '', '@MiamiDadeCounty', 'http://www.miamidade.gov/environment/'),
('Miami-Dade', 'DCF', 'Department of Children & Families', 'regional contact', 'Paige Patterson-Hughes', '954-375-3354', '954-410-3931', 'Paige.PattersonHughes@myflfamilies.com', '', '@MyFLFamilies', 'http://www.myflfamilies.com/'),
('Miami-Dade', 'DMV', 'Department of Highway and Motor Vehicle Safety', '', '', '850-617-3102 ', '', 'HSMV-Media@flhsmv.gov', '', '@FLHSMV', 'http://www.flhsmv.gov/'),
('Miami-Dade', 'DOC', 'Florida Department of Corrections', 'Director of Communications', 'McKinley Lewis', '850-488-0420', '', 'lewis.mckinley@mail.dc.state.fl.us', '', '', 'http://www.dc.state.fl.us/orginfo/pubaff.html'),
('Miami-Dade', 'Doral PD', '', 'PIO', 'Sgt. Cathy Jewett', ' 305-593-6699 ext. 2111', '', 'Cathy.Jewett@doralpd.com', '', '@Cityofdoral', 'http://www.cityofdoral.com/index.php?option=com_content&view=article&id=130&Itemid=317'),
('Miami-Dade', 'FAA', 'Federal Aviation Administration', '', 'Kathleen Bergen', '(404) 305-5100', '', '', '', '@FAANews', 'http://www.faa.gov/news/'),
('Miami-Dade', 'FBI', 'Federal Bureau of Investigations', '', 'Special Agent Michael D. Leverock', '(754) 703-2000', '', 'Miami@ic.fbi.gov', '', '@FBIMiamiFL', 'https://www.fbi.gov/miami'),
('Miami-Dade', 'FDLE', 'Florida Department of Law Enforcement', '', '', '850-410-7001', '', 'info@fdle.state.fl.us', '', '', 'https://www.fdle.state.fl.us/Content/home.aspx'),
('Miami-Dade', 'FHP', 'Florida Highway Patrol', '', 'Trooper Jose Sanchez', '(305) 718-6020', '', 'JoseSanchez@flhsmv.gov', '', '@FLHSMV', 'http://www.flhsmv.gov/florida-highway-patrol/about-fhp/'),
('Miami-Dade', 'Florida Division of Forestry', '', 'Wildfire Mitigation Specialist', 'Scott Peterich', '(561) 791-4725', '(954) 347-8062 ', 'Scott.Peterich@FreshFromFlorida.com', '', '@FFS_Everglades', 'http://www.freshfromflorida.com/Divisions-Offices/Florida-Forest-Service'),
('Miami-Dade', 'FIU PD', 'Florida International University Police Department', '', '', '305-348-2623 ', '305-348-2626', 'adcasas@fiu.edu', '', '@FIUPOLICE', 'http://police.fiu.edu/information/information.html'),
('Miami-Dade', 'FWC', 'Florida Fish & Wildlife Conservation Commission', '', 'Officer Jorge Pino', '561-723-1417', '', 'Jorge.Pino@myfwc.com', '', '@MyFWC', 'http://myfwc.com/news/contacts/'),
('Miami-Dade', 'FPL', 'Florida Power & Light', '', '', '561-694-4442', '', 'media.relations@fpl.com', '', '@insideFPL', 'https://www.fpl.com/'),
('Miami-Dade', 'Hialeah PD', '', '', '', '305-687-2525', '', '', '', '', 'http://www.hialeahfl.gov/index.php?option=com_content&view=article&id=128&Itemid=382&lang=en'),
('Miami-Dade', 'Hialeah Gardens PD', '', '', 'Captain Luis Diaz', '305) 558-3333', '305-558-3333', 'capt.diaz@cityofhialeahgardens.com', '', '', 'http://www.cityofhialeahgardens.com/cohg2/index.php?option=com_content&view=article&id=54&Itemid=29'),
('Miami-Dade', 'Homestead PD', '', '', 'Detective Fernando Morales', '305-224-5303', '305-247-1535', 'fmorales@homesteadpolice.com ', '', '@HomesteadPD_FL', 'http://www.cityofhomestead.com/index.aspx?nid=104'),
('Miami-Dade', 'ICE', 'Immigration and Customs Enforcement', '', 'Nestor Yglesias', '305-597-6032', '305- 502-6886', 'Nestor.J.Yglesias@ice.dhs.gov', 'ICEMedia@ice.dhs.gov', '@ICEgov', 'http://www.ice.gov/'),
('Miami-Dade', 'IRS', 'Internal Revenue Service', 'regional contact', 'Michael Dobzinski', '954-423-7640', '', '', '', '@IRSnews', 'http://www.irs.gov/uac/IRS-Media-Relations-Offices---Contact-Numbers'),
('Miami-Dade', 'Jackson Memorial Hospital', '', '', '', '305-585-7213', '', '', '', '@jacksonhealth', 'http://www.jacksonhealth.org/'),
('Miami-Dade', 'Key Biscayne PD', '', '', ' Police Chief Charles Press ', '305-519-0801 ', '', '', '', '', 'http://www.kbpd.net/'),
('Miami-Dade', 'Miami Fire Rescue', '', '', 'Captain Ignatius Carroll', '  305-416-1625', '305-579-6275', '  icarroll@miamigov.com. ', '', '', 'http://www.miamigov.com/Fire/pages/default.asp'),
('Miami-Dade', 'Miami PD', '', '', '', '305-603-6420', '305-579-6111.', '', '', '', 'http://www.miami-police.org/index.asp'),
('Miami-Dade', 'Miami Beach Fire Rescue', '', '', '', '305.673.7111', '305.673.7120', '', '', '@MiamiBeachNews', 'http://miamibeachfl.gov/fire/'),
('Miami-Dade', 'Miami Beach PD', '', '', '', '305-673-7383', '305-673-7901', '', '', '@MiamiBeachPD', 'http://miamibeachfl.gov/pd/'),
('Miami-Dade', 'Miami-Dade Animal Services', '', '', 'Kathy Labrada', '305-418-7172', '', 'klabrad@miamidade.gov', '', '@PetsToLove', 'http://www.miamidade.gov/animals/'),
('Miami-Dade', 'Miami-Dade College', '', '  MDC Communications Director', ' Juan Mendieta', '  305-237-7611', '', 'jmendiet@mdc.edu', '', '@MDCollege', 'http://www.mdc.edu/mdcglobal/ci/press-media/'),
('Miami-Dade', 'Miami-Dade Corrections', '', '', 'Janelle Hall', '', '', 'taea@miamidade.gov', '', '', 'http://egvsys.metro-dade.com:1608/wwwserv/crts/IPSAWNSI.DIA'),
('Miami-Dade', 'Miami-Dade County Hall', '', '', 'Suzy Trutie', '305-375-4883', '', 'strutie@miamidade.gov', '', '@MiamiDadeCounty', 'http://www.miamidade.gov/'),
('Miami-Dade', 'Miami-Dade Fire Rescue', '', '', '', '786-331-5200', '786-336-6633 ', 'mdfrd@miamidade.gov', '', '@MiamiDadeFire', 'http://www.miamidade.gov/fire/contact.asp'),
('Miami-Dade', 'Miami-Dade Medical Examiners Office', '', '', 'Larry Cameron', '305-545-2487', '305-545-2425', '', '', '@MiamiDadeCounty', 'http://www.miamidade.gov/medexam/search.asp'),
('Miami-Dade', 'Miami-Dade PD', '', '', '', '305-471-1900', '', '', '', '@MiamiDadePD', 'http://www.miamidade.gov/police/'),
('Miami-Dade', 'Miami-Dade Public Schools', '', '', 'Daisy Gonzalez-Diego', '305-995-2060 ', '', 'dgonzalezdiego@dadeschools.net', '', '@MDCPS', 'http://www.dadeschools.net/'),
('Miami-Dade', 'Miami-Dade School Police', '', '', 'Lt. Raul Correa ', '305.757.7708', '', 'rcorrea@dadeschools.net ', '', '', 'http://mdspolice.com/'),
('Miami-Dade', 'Miami-Dade Public Works', '', '', 'Delfin A. Molins', '305-375-1682', '', 'delfin@miamidade.gov', '', '@MiamiDadeCounty', 'http://www.miamidade.gov/publicworks/'),
('Miami-Dade', 'Miami-Dade State Attorneys Office', '', '', 'Ed Griffith', '305-547-0535', '', '', '', '@KathyFndzRundle', 'http://www.miamisao.com/'),
('Miami-Dade', 'Miami-Dade Transit', '', '', 'Karla Damian', '786-469-5420 ', '', '', '', '@IRideMDT', 'http://www.miamidade.gov/transit/'),
('Miami-Dade', 'Miami Gardens PD', '', '', '', '305-332-4241. ', '(305) 474-6473. ', '', '', '', 'http://www.miamigardenspolice.org/'),
('Miami-Dade', 'Miami International Airport', '', '', '', '305-876-7017', '305-342-1849', '', '', '@iflymia', 'http://www.miami-airport.com/'),
('Miami-Dade', 'Mount Sinai Medical Center', '', '', 'Joanna Palmer', '305-674-2589', '', 'joanna.palmer@msmc.com', '', '@MountSinaiMiami', 'http://www.msmc.com/'),
('Miami-Dade', 'National Hurricane Center', '', '', 'Dennis Feltgen', '305-229-4404', '305-229-4414', '', '', '@NWSNHC', 'http://www.nhc.noaa.gov/'),
('Miami-Dade', 'National Weather Service', '', '', '', '305-229-4502 ', '305-229-4528', '', '', '@NWS', 'http://www.weather.gov/'),
('Miami-Dade', 'North Miami PD', '', '', '', '305.891.0294', '', '', '', '@north_pd', 'http://www.northmiamipolice.com/'),
('Miami-Dade', 'North Miami Beach PD', '', '', 'Maj. Kathy Katerman', '305-948-2940', '305-662-7654', '', '', '@myNMBPolice', 'http://www.citynmb.com/index.asp?Type=B_BASIC&SEC=%7B091256C6-84B0-424A-818A-CEC51C604620%7D'),
('Miami-Dade', 'NTSB', 'National Transportation Safety Board', '', '', '305-597-4611', '(202) 314-6100', '', '', '@NTSB', 'http://www.ntsb.gov/news/Pages/default.aspx'),
('Miami-Dade', 'South Miami PD', '', 'Communications Supervisor', 'Lisa Corbin', '305.663.6311', '305-663-6301', 'lcorbin@southmiamifl.gov', '', '@SoMiamiPolice', 'http://www.southmiamifl.gov/index.aspx?NID=184'),
('Miami-Dade', 'Southern Command', '', '', '', '305-437-1201', '305-437-4900', '', '', '@southcomwatch', 'http://www.southcom.mil/Pages/Default.aspx'),
('Miami-Dade', 'Sunny Isles Beach', '', '', 'Police Chief Fred Maas', '305.947.4440', '', '', '', '@CityofSIB', 'http://www.sibfl.net/city-hall/departments/police-department/'),
('Miami-Dade', 'Sweetwater Police', '', 'Chief of Police ', 'Placido Diaz', '(305) 552-9900', '', ' pdiaz@cityofsweetwater.fl.gov', '', '@CitySweetwater', 'http://cityofsweetwater.fl.gov/index.html'),
('Miami-Dade', 'Tri-Rail', '', 'spokeswoman', 'Bonnie Arnold', '954-788-7936.', '', '', '', '@Tri_Rail', 'http://www.tri-rail.com/'),
('Miami-Dade', 'U.S. Coast Guard', '', '', '', '305-415-6683', '305-415-6800. ', '', '', '@USCG', 'http://www.uscg.mil/d7/sectmiami/'),
('Miami-Dade', 'U.S. Secret Service', '', '', '', '202-406-5708', '561-659-0184', '', '', '@SecretService', 'http://www.secretservice.gov/'),
('Miami-Dade', 'University of Miami', '', 'Media contact', 'Liz Amore', '305 284 5500', '', '', '', '@univmiami', 'http://welcome.miami.edu/http://welcome.miami.edu/'),
('Miami-Dade', 'University of Miami Medical School', '', 'media contact', 'Lisa Worley ', '305-243-5184', '305-458-9654', 'lworley2@med.miami.edu', '', '@UHealthMiami', 'http://www.med.miami.edu/');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `hash` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=11 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `hash`) VALUES
(1, 'belindazeng', '$1$50$oxJEDBo9KDStnrhtnSzir0'),
(2, 'caesar', '$1$50$GHABNWBNE/o4VL7QjmQ6x0'),
(3, 'jharvard', '$1$50$RX3wnAMNrGIbgzbRYrxM1/'),
(4, 'malan', '$1$50$lJS9HiGK6sphej8c4bnbX.'),
(5, 'rob', '$1$HA$l5llES7AEaz8ndmSo5Ig41'),
(6, 'skroob', '$1$50$euBi4ugiJmbpIbvTTfmfI.'),
(7, 'zamyla', '$1$50$uwfqB45ANW.9.6qaQ.DcF.'),
(8, 'rpiccardo', '$1$LTTda0/m$eMTG.USl3BkaDKiAyqFG/0'),
(9, 'fjzerpa', '$1$mOdl/r6t$BGdL2ANMdjJuDHtqA8d0o0'),
(10, 'luisachacon', '$1$zwiFhjvF$m.6P2Xoi7IyRQYHA5yBxN.');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
